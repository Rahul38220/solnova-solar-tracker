# Solnova ☀️

**Solnova** is an intelligent, dual-axis solar tracking system engineered to maximize solar energy harvest while actively mitigating thermal efficiency loss. Built for the **EEP Competition**, Solnova combines real-time light tracking with an automated water-spray cooling mechanism to ensure solar panels operate at peak performance.

---

## 📌 Project Overview

Solar panel efficiency degrades as surface temperature rises beyond optimal thresholds. Solnova addresses both orientation and thermal management in a single prototype:

* **Dual-Axis Tracking:** Uses Light Dependent Resistors (LDRs) and servo motors to follow the sun's trajectory dynamically across both horizontal (azimuth) and vertical (elevation) axes.
* **Active Thermal Management:** Integrated temperature sensors monitor panel surface heat. When temperatures exceed operational thresholds, an automated water spray cooling cycle triggers to restore optimal photovoltaic output.
* **3D-Printed Custom Base:** Custom mechanical housing and rotation structures designed and optimized for rapid prototyping and modular assembly.

---

## 🗂️ Repository Structure

```text
.
├── code/
│   └── code.ino        # Arduino sketch for dual-axis tracking & cooling logic
├── models/
│   ├── files /            # (.stl) 3D printable files for the rotating base & mount
│   └── images/            # Assembly photos, CAD renders, and mechanical documentation
├── .gitignore             # Standard git ignore file
└── README.md              # Project documentation
```
---

## ⚙️ How It Works
### 1. Light Tracking Mechanism

Four LDR sensors are arranged in a quadrant grid on the panel frame. The microcontroller compares light intensities:

    Top vs. Bottom: Controls the vertical tilt servo.

    Left vs. Right: Controls the horizontal rotational servo.

### 2. Active Cooling System

A temperature sensor continuously measures the panel's temperature. When the surface heat crosses the calibrated setpoint, a relay activates a water pump/sprayer to lower the panel temperature, combating heat-induced efficiency drop.
🛠️ Hardware Components

    Microcontroller: Arduino Uno

    Actuators: 2× Servo Motors 

    Sensors: 4× LDR Sensors, 1× Temperature Sensor (DHT11)

    Cooling Relay: 5V Relay module connected to a mini water pump/solenoid spray nozzle

    Structure: Custom 3D-printed mounting base (.stl files located in /models)

### 🚀 Getting Started

    Hardware Assembly:

        Print all mechanical components located in the /models folder.

        Assemble the dual-axis gimbal base and mount the servo motors and LDR sensor array.

    Upload Code:

        Open the .ino sketch from the /code directory in the Arduino IDE.

        Connect your Arduino via USB and click Upload.

    Calibration:

        Adjust the LDR differential threshold and temperature setpoint in solnova.ino to suit your testing environment.

### 🏆 Competition Context

Developed for the EEP Competition, Solnova demonstrates a working hardware prototype that directly addresses photovoltaic overheating—a key obstacle in solar energy efficiency identified in contemporary solar research.
