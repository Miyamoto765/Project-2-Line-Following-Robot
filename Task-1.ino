// ============================================================
// Line Follower - Task 1: Basic Motor Control
// L298N pins
// Intern Name: AHAMED KABEER PH
// Intern ID : SN1001774
// ============================================================

#define ENA 5   // Motor A (left) speed - PWM
#define ENB 6   // Motor B (right) speed - PWM
#define IN1 7   // Motor A dir bit 1
#define IN2 8   // Motor A dir bit 2
#define IN3 9   // Motor B dir bit 1
#define IN4 10  // Motor B dir bit 2

const int SPEED = 200; // 0-255, tune for 7.4V pack (lower than 9V equiv since less voltage drop needed)

void setup() {
  Serial.begin(9600);   // Added for Serial Monitor

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  Serial.println("Moving Forward");
  forward();
  delay(2500);

  Serial.println("Stopped");
  stopMotors();
  delay(500);

  Serial.println("Turning Left");
  turnLeft();
  delay(2000);

  Serial.println("Stopped");
  stopMotors();
  delay(500);

  Serial.println("Turning Right");
  turnRight();
  delay(2200);

  Serial.println("Stopped");
  stopMotors();
  delay(500);

  Serial.println("Moving Backward");
  backward();
  delay(2500);

  Serial.println("Stopped");
  stopMotors();
  delay(2000); // pause before loop repeats
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);
}

void turnLeft() {
  // left motor backward/stop, right motor forward -> pivot left
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, SPEED);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
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