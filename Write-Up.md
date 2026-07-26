# Project 2: Autonomous Line Following Robot

**Platform:** Arduino Uno

**Modules:** L298N Motor Driver, 2× IR Line Tracking Sensors

**Internship:** Soft Nexis Technology – Embedded Systems

**Intern Name**: AHAMED KABEER PH

**Intern ID **: SN1001774

---

## Overview

This project builds a robot that follows a black line on a white surface without human control. Two IR sensors continuously scan the surface the Arduino interprets their readings and motor commands are sent through a driver to steer the robot along the path in real time.

---

## Task 1: Motor Control Setup and Testing

### Description

Before adding sensors the base movement system was. Verified. Two BO DC motors were wired to a motor driver, which was in turn connected to the Arduino (ENA/ENB on D5/D6 IN1–IN4 on D7–D10). The Arduino itself was powered off the L298Ns onboard 5V regulator output, fed into the Arduinos Vin pin. The whole system ran off a single battery source. Basic movement functions. Left turn right turn and stop. Were coded and tested independently to confirm the drivetrain worked correctly before layering sensor logic on top.

### Issue Faced

Two separate issues came up here.

First power supply: a 9V battery connected to the L298N was not sufficient to drive both motors and power the Arduino through Vin at the same time. Voltage sagged under load. A 4×AA battery pack was tried next as a replacement. This also failed to deliver stable power to both the motors and the Arduino.

Second once power was stabilized one of the two BO motors consistently rotated slower than the other causing the robot to drift off a path even with identical motor commands sent to both sides.

### Solution

For power the setup was moved to 2×18650 Li-ion cells (7.4V) which provided current headroom for the motors while keeping the Arduino stable via the L298Ns 5V-to-Vin feed. This required a bit of trial and error across the 9V and 4×AA attempts before landing on the 18650 pack as the reliable source.

For the motor imbalance individual motor speeds were adjusted via PWM (through ENA/ENB) than assuming both motors would behave identically at the same input. Once both the power source and motor balance were sorted the robot moved in a line reliably confirmed through repeated forward-motion tests.

---

## Task 2: Line Detection and Autonomous Following

### Description

With the drivetrain verified two IR sensors were added. One on the left one on the right (connected to D3 and D4). Each sensor detects the surface beneath it: white surfaces reflect infrared light than black ones. Based on the combination of /right sensor states the Arduino decides whether to move forward turn left turn right or stop, allowing the robot to track a black line on a white background continuously and without intervention.

### Issue Faced

The robot initially moved incorrectly on the track. The code assumed HIGH and white = LOW but the actual IR modules produced the opposite output (black = LOW white = HIGH). This logic mismatch caused the robot to turn the way whenever it detected the line and it also struggled with sharp 90° turns at higher speeds.

### Solution

The sensor logic in code was corrected by defining explicit `LINE` and `NO_LINE` constants matched to the actual module behavior, rather than hardcoding assumed values. Sensor sensitivity was also calibrated using the potentiometer and motor speed was reduced specifically for turns to improve cornering accuracy. Serial Monitor output (sensor states + current action) was used throughout to confirm behavior before finalizing the code.

---

## Result

The robot successfully followed an electrical tape line on a white chart paper track. Detecting the line correcting drift with left/right turns and stopping at the end of the track with all sensor states and actions logged live via Serial Monitor.

## Skills Gained

Digital sensor interfacing, L298N motor driver control, PWM speed tuning, real-time decision logic (if-else based) and hardware debugging, via Serial Monitor.
