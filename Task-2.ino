// ============================================================
// Line Following Robot – Task 2 : Autonomous Line Follower
// Based on Task 1 Motor Control
// Intern Name: AHAMED KABEER PH
// Intern ID : SN1001774
// ============================================================

// ---------- L298N Motor Driver Pins ----------
#define ENA 5   // Motor A (Left) Speed
#define ENB 6   // Motor B (Right) Speed
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10

// ---------- IR Sensor Pins ----------
#define IR_LEFT 3
#define IR_RIGHT 4

// ---------- Speed ----------
const int SPEED = 150;

// ---------- Sensor Values ----------
// Most IR modules:
// WHITE = LOW
// BLACK = HIGH
const int LINE = LOW;
const int NO_LINE = HIGH;

void setup() {

  Serial.begin(9600);

  // Motor Pins
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // IR Sensor Pins
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  Serial.println("==================================");
  Serial.println("Line Follower Ready!");
  Serial.println("Place Robot on Track...");
  Serial.println("==================================");

  delay(3000);
}

void loop() {

  int leftSensor = digitalRead(IR_LEFT);
  int rightSensor = digitalRead(IR_RIGHT);

  // Display sensor readings
  Serial.print("Left: ");
  Serial.print(leftSensor);
  Serial.print("   Right: ");
  Serial.println(rightSensor);

  // Decision Logic
  if (leftSensor == NO_LINE && rightSensor == NO_LINE) {

    forward();
    Serial.println("Action : FORWARD");

  }
  else if (leftSensor == LINE && rightSensor == NO_LINE) {

    turnLeft();
    Serial.println("Action : TURN LEFT");

  }
  else if (leftSensor == NO_LINE && rightSensor == LINE) {

    turnRight();
    Serial.println("Action : TURN RIGHT");

  }
  else {

    stopMotors();
    Serial.println("Action : STOP");

  }

  Serial.println("------------------------");
  delay(500);
}

// ================= Motor Functions =================

void forward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);
}

void turnLeft() {

  // Stop Left Motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Run Right Motor
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, SPEED);
}

void turnRight() {

  // Run Left Motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Stop Right Motor
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, SPEED);
  analogWrite(ENB, 0);
}

void stopMotors() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}