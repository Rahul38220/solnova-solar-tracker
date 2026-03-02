#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
#define RELAY_PIN 7
#define SERVO_PIN 9

// LDR pins
const int ldrTopLeft = A0;
const int ldrTopRight = A1;
const int ldrBottomLeft = A2;
const int ldrBottomRight = A3;

Servo horizontalServo;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int servoPosition = 90;
const int minServo = 60;
const int maxServo = 120;
const int threshold = 20;
const float tempThreshold = 45.0;

void setup() {
  Serial.begin(9600);
  sensors.begin();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Pump OFF

  horizontalServo.attach(SERVO_PIN);
  horizontalServo.write(servoPosition);

  pinMode(ldrTopLeft, INPUT);
  pinMode(ldrTopRight, INPUT);
  pinMode(ldrBottomLeft, INPUT);
  pinMode(ldrBottomRight, INPUT);
}

void loop() {
  // --------- LDR SUN TRACKING ---------
  int tl = analogRead(ldrTopLeft);
  int tr = analogRead(ldrTopRight);
  int bl = analogRead(ldrBottomLeft);
  int br = analogRead(ldrBottomRight);

  int avgLeft = (tl + bl) / 2;
  int avgRight = (tr + br) / 2;
  int diff = avgLeft - avgRight;

  if (diff < -threshold && servoPosition < maxServo) {
    servoPosition++;
    horizontalServo.write(servoPosition);
    delay(15);
  } else if (diff > threshold && servoPosition > minServo) {
    servoPosition--;
    horizontalServo.write(servoPosition);
    delay(15);
  }

  // --------- TEMPERATURE + PUMP ---------
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print("°C | Servo: ");
  Serial.println(servoPosition);

  if (tempC > tempThreshold) {
    digitalWrite(RELAY_PIN, LOW);  // Pump ON
  } else {
    digitalWrite(RELAY_PIN, HIGH);   // Pump OFF
  }

  delay(1000); // Wait before next loop
}
