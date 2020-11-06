#include<NewPing.h>

#define TRIGGER_PIN 2
#define ECHO_PIN 2
#define MAX_DISTANCE 255

#define MOTOR_1_STEP_PIN 3
#define MOTOR_1_DIR_PIN 4

#define MOTOR_2_STEP_PIN 5
#define MOTOR_2_DIR_PIN 6

#define MOTOR_3_STEP_PIN 7
#define MOTOR_3_DIR_PIN 8

#define X A0
#define Y A1

char ch;
int x_pos;
int y_pos;
float distance;

NewPing sensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void front(int);
void back(int);
void left(int);
void right(int);
void stopMotor();

void setup() {

  pinMode(MOTOR_1_STEP_PIN, OUTPUT);
  pinMode(MOTOR_1_DIR_PIN, OUTPUT);

  pinMode(MOTOR_2_STEP_PIN, OUTPUT);
  pinMode(MOTOR_2_DIR_PIN, OUTPUT);

  pinMode(MOTOR_3_STEP_PIN, OUTPUT);
  pinMode(MOTOR_3_DIR_PIN, OUTPUT);

  pinMode(X, INPUT);
  pinMode(Y, INPUT);
}

void loop() {

  distance = sensor.ping_cm();

  if (distance > 20) {
    x_pos = analogRead(X);
    y_pos = analogRead(Y);
    if (x_pos > 800) {
      front(800);
    }
    else if (x_pos < 200) {
      back(800);
    }
    else if (y_pos > 650) {
      right(800);
    }
    else if (y_pos < 350) {
      left(800);
    }
    else {
      stopMotor();
    }
  }
  else {
    stopMotor();
  }
}

void front(int spd) {

  digitalWrite(MOTOR_1_DIR_PIN, ~digitalRead(MOTOR_1_DIR_PIN));
  digitalWrite(MOTOR_2_DIR_PIN, LOW);
  digitalWrite(MOTOR_3_DIR_PIN, HIGH);

  for (int i = 0; i < 200; i++) {
    digitalWrite(MOTOR_2_STEP_PIN, HIGH);
    digitalWrite(MOTOR_3_STEP_PIN, HIGH);
    delayMicroseconds(spd);
    digitalWrite(MOTOR_2_STEP_PIN, LOW);
    digitalWrite(MOTOR_3_STEP_PIN, LOW);
    delayMicroseconds(spd);
  }
}

void back(int spd) {

  digitalWrite(MOTOR_1_DIR_PIN, ~digitalRead(MOTOR_1_DIR_PIN));
  digitalWrite(MOTOR_2_DIR_PIN, HIGH);
  digitalWrite(MOTOR_3_DIR_PIN, LOW);

  for (int i = 0; i < 200; i++) {
    digitalWrite(MOTOR_2_STEP_PIN, HIGH);
    digitalWrite(MOTOR_3_STEP_PIN, HIGH);
    delayMicroseconds(spd);
    digitalWrite(MOTOR_2_STEP_PIN, LOW);
    digitalWrite(MOTOR_3_STEP_PIN, LOW);
    delayMicroseconds(spd);
  }
}

void left(int spd) {

  digitalWrite(MOTOR_2_DIR_PIN, ~digitalRead(MOTOR_2_DIR_PIN));
  digitalWrite(MOTOR_1_DIR_PIN, LOW);
  digitalWrite(MOTOR_3_DIR_PIN, HIGH);

  for (int i = 0; i < 200; i++) {
    digitalWrite(MOTOR_1_STEP_PIN, HIGH);
    digitalWrite(MOTOR_3_STEP_PIN, HIGH);
    delayMicroseconds(spd);
    digitalWrite(MOTOR_1_STEP_PIN, LOW);
    digitalWrite(MOTOR_3_STEP_PIN, LOW);
    delayMicroseconds(spd);
  }
}

void right(int spd) {

  digitalWrite(MOTOR_2_DIR_PIN, ~digitalRead(MOTOR_2_DIR_PIN));
  digitalWrite(MOTOR_1_DIR_PIN, HIGH);
  digitalWrite(MOTOR_3_DIR_PIN, LOW);

  for (int i = 0; i < 200; i++) {
    digitalWrite(MOTOR_1_STEP_PIN, HIGH);
    digitalWrite(MOTOR_3_STEP_PIN, HIGH);
    delayMicroseconds(spd);
    digitalWrite(MOTOR_1_STEP_PIN, LOW);
    digitalWrite(MOTOR_3_STEP_PIN, LOW);
    delayMicroseconds(spd);
  }
}

void stopMotor() {

  digitalWrite(MOTOR_1_DIR_PIN, ~digitalRead(MOTOR_1_DIR_PIN));
  digitalWrite(MOTOR_2_DIR_PIN, ~digitalRead(MOTOR_2_DIR_PIN));
  digitalWrite(MOTOR_3_DIR_PIN, ~digitalRead(MOTOR_3_DIR_PIN));
}
