# Project 2 - Robot that Follows a Line: Report

This project consisted of two components: Task 1 created the fundamental robot with manual control, while Task 2 developed it further into an autonomous line follower utilizing IR sensors.

## Task 1: Manual Control of Movement

The initial obstacle was accurately connecting the L298N motor driver. Mixing up the ENA/ENB (speed) and IN1-IN4 (direction) pins led to the motors rotating in unintended directions or failing to move. Verifying the pin table with the real wiring and testing each motor separately using basic HIGH/LOW pairs fixed this issue.

The second issue was a problem of shared ground. At first, the 9V battery supplying power to the motors and the Arduino lacked a ground connection, leading to erratic and inconsistent motor performance because the L298N and Arduino did not have a common voltage reference. Linking the battery GND to the Arduino GND resolved this right away.

The greatest obstacle was motor strength. One 9V battery was insufficient to supply adequate current for both DC motors - the robot performed slowly and halted under strain as the voltage dropped rapidly. Changing to a 4xAA Duracell Ultra Alkaline pack (6V, significantly greater current capacity) resolved this entirely, providing the motors with stable, consistent torque.

## Task 2: Self-Guided Line Tracking

With the fundamental robot functioning consistently, the primary obstacle was calibrating the IR sensor. The onboard potentiometer required precise tuning to ensure the sensor LED consistently turned OFF on a white surface and ON over a black line, as varying thresholds led to incorrect readings and caused the robot to veer off course. Testing each sensor individually on the track surface prior to installation resolved this issue.

Ultimately, adjusting the turn logic (BLACK/WHITE combinations assigned to Forward/Left/Right/Stop) necessitated multiple iterations to achieve fluid, non-jittery motion rather than abrupt overcorrections at the line boundaries.

## Summary

The biggest takeaways were power delivery, grounding, and sensor calibration - hardware-level problems that aren't visible in code but directly determine reliability.