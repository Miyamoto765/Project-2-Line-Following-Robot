# Project 2 – Line Following Robot

Arduino-based Line Following Robot project using an L298N motor driver and two IR sensors, developed during the Soft Nexis Technology Embedded Systems Internship.

## Overview

This project implements two tasks using an Arduino:

1. **Task 1 – Manual Movement Control**: Drives two DC motors via an L298N motor driver through a fixed sequence — Forward → Stop → Left → Right → Backward.
2. **Task 2 – Autonomous Line Following**: Reads two IR sensors placed at the front-bottom of the chassis to detect a black line on a white track and automatically steers the robot to stay on course.

## Hardware Used

- Arduino UNO
- L298N Motor Driver
- 2x DC Geared Motors (Left/Right)
- 2x IR Line Sensor Modules
- 4xAA Duracell Ultra Alkaline battery pack, 6V (motor power)
- Chassis + wheels + breadboard/jumper wires

## Task 1 – L298N Motor Control

**File:** `Task_1.ino`

| From | To | Note |
|---|---|---|
| Arduino Pin 5 (PWM) | L298N ENA | Speed control – Motor A (Left) |
| Arduino Pin 6 (PWM) | L298N ENB | Speed control – Motor B (Right) |
| Arduino Pin 7 | L298N IN1 | Motor A direction bit 1 |
| Arduino Pin 8 | L298N IN2 | Motor A direction bit 2 |
| Arduino Pin 9 | L298N IN3 | Motor B direction bit 1 |
| Arduino Pin 10 | L298N IN4 | Motor B direction bit 2 |
| L298N OUT1 & OUT2 | Left motor terminals | Power wires to left motor |
| L298N OUT3 & OUT4 | Right motor terminals | Power wires to right motor |
| Battery + | L298N 12V input | Motor power supply |
| Battery − | L298N GND + Arduino GND | Common ground (critical) |

**Motor Truth Table (IN1/IN2 shown; IN3/IN4 same logic for Motor B):**

| IN1 | IN2 | Direction |
|---|---|---|
| HIGH | LOW | Forward |
| LOW | HIGH | Backward |
| LOW | LOW | Stop (coast) |
| HIGH | HIGH | Stop (brake) |

- **Logic:** Runs the fixed sequence Forward → Stop → Left → Right → Backward, printing each movement to the Serial Monitor.

## Task 2 – IR Sensor Line Following

**File:** `Task_2.ino`

| From | To | Note |
|---|---|---|
| Left IR Sensor VCC | Arduino 5V | Power |
| Left IR Sensor GND | Arduino GND | Ground |
| Left IR Sensor OUT | Arduino Pin 3 | Digital output to Arduino |
| Right IR Sensor VCC | Arduino 5V | Power |
| Right IR Sensor GND | Arduino GND | Ground |
| Right IR Sensor OUT | Arduino Pin 4 | Digital output to Arduino |

- **Left IR pin:** 3
- **Right IR pin:** 4
- **Calibration:** Onboard blue potentiometer adjusts sensitivity — LED OFF over white, ON over black line. Test before mounting.
- **Logic:** Reads both IR sensors continuously and drives motors based on the combination:

| Left IR | Right IR | Meaning | Action |
|---|---|---|---|
| WHITE | WHITE | On track centre | Go Forward |
| BLACK | WHITE | Drifting right | Turn Left |
| WHITE | BLACK | Drifting left | Turn Right |
| BLACK | BLACK | Intersection / End | Stop |

**Required Library:** None (uses standard `digitalRead`/`digitalWrite`)

## Repository Structure

```
Project-2-Line-Following-Robot/
├── README.md
├── Task_1.ino
├── Task_2.ino
├── writeup.md
└── media/
    ├── task1_chassis_top.jpg
    ├── task1_chassis_bottom.jpg
    ├── task1_serial_monitor.png
    ├── task1_demo_video.mp4
    ├── task2_ir_sensor_placement.jpg
    ├── task2_serial_monitor.png
    └── task2_demo_video.mp4
```
