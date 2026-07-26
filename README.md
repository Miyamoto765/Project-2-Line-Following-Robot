# Project 2 – Line Following Robot

Arduino Uno based robot that autonomously follows a black line on a white surface using IR sensors and an L298N motor driver.

---

## Overview

The robot uses two IR sensors to continuously scan the surface beneath it. Based on the combination of readings, the Arduino decides whether to move forward, turn left, turn right, or stop — allowing it to track a line in real time without human control.

Full writeup with issues faced and solutions: [Write-Up.md](./Write-Up.md)

---

## Hardware Used

- Arduino Uno
- L298N Motor Driver Module
- 2× BO DC Motors + Wheels
- Robot Chassis + Caster Wheel
- 2× IR Line Tracking Sensors
- 2× 18650 Li-ion Batteries (7.4V)
- Black electrical tape + white chart paper (track)

---

## Repo Structure

```
├── Media/
│   ├── Task-1/
│   │   ├── Task1_chassis_bottom.jpeg
│   │   ├── Task1_chassis_top.jpeg
│   │   ├── Task1_demo_video.mp4
│   │   └── Task1_serial_monitor.png
│   └── Task-2/
│       ├── Task2_Serial_monitior.mp4
│       ├── Task2_chassis_bottom.jpeg
│       ├── Task2_chassis_top.jpeg
│       ├── Task2_demo_video.mp4
│       └── ino
├── README.md
├── Task-1.ino
├── Task-2.ino
└── Write-Up.md
```

---

## Task 1: Motor Control Setup and Testing

Base drivetrain built and verified before adding sensors. Arduino powered off the L298N's onboard 5V regulator into Vin. Forward, left, right, and stop functions coded and tested independently.

- Code: [Task-1.ino](./Task-1.ino)
- Chassis: [bottom](./Media/Task-1/Task1_chassis_bottom.jpeg) · [top](./Media/Task-1/Task1_chassis_top.jpeg)
- Demo video: [Task1_demo_video.mp4](./Media/Task-1/Task1_demo_video.mp4)
- Serial monitor: [Task1_serial_monitor.png](./Media/Task-1/Task1_serial_monitor.png)

**Issues faced:** insufficient power from 9V and 4×AA sources, motor speed imbalance between the two BO motors.
**Fixed by:** switching to a 2×18650 Li-ion supply and PWM-balancing motor speeds via ENA/ENB. Full details in [Write-Up.md](./Write-Up.md).

---

## Task 2: Line Detection and Autonomous Following

Two IR sensors added (left on D3, right on D4). Robot decides direction based on sensor states and follows a black tape line on white chart paper.

- Code: [Task-2.ino](./Media/Task-2/ino)
- Chassis: [bottom](./Media/Task-2/Task2_chassis_bottom.jpeg) · [top](./Media/Task-2/Task2_chassis_top.jpeg)
- Demo video: [Task2_demo_video.mp4](./Media/Task-2/Task2_demo_video.mp4)
- Serial monitor: [Task2_Serial_monitior.mp4](./Media/Task-2/Task2_Serial_monitior.mp4)

**Issues faced:** sensor logic mismatch (black/white HIGH-LOW assumption reversed), incorrect turning direction, poor sharp-turn handling at speed.
**Fixed by:** correcting `LINE`/`NO_LINE` constants to match actual sensor output, calibrating sensor sensitivity via onboard potentiometer, reducing speed on turns. Full details in [Write-Up.md](./Write-Up.md).

---

## Sensor Logic

| Left Sensor | Right Sensor | Meaning | Action |
|---|---|---|---|
| White | White | On track | Forward |
| Black | White | Drifted right | Turn Left |
| White | Black | Drifted left | Turn Right |
| Black | Black | End of line / intersection | Stop |

---

## Skills Gained

Digital sensor interfacing, L298N motor driver control, PWM speed tuning, real-time decision logic, power supply troubleshooting, hardware debugging via Serial Monitor.
