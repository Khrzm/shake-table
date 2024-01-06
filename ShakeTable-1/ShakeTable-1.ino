#include <AccelStepper.h>

int stepPin = 6;
int dirPin = 9;
int enblPin = 12;
int n = 0;

AccelStepper stepper(AccelStepper::DRIVER, stepPin, dirPin);

void setup() {
  pinMode(enblPin, OUTPUT);
  digitalWrite(enblPin, HIGH); // Disable the motor

  Serial.begin(9600);
  Serial.println("init");

  delay(100);

  // You can set additional parameters for your stepper motor here, such as max speed and acceleration
  stepper.setMaxSpeed(50000.0);
  stepper.setAcceleration(50000.0);
}

void loop() {
  digitalWrite(enblPin, LOW); // Enable the motor

  n = random(0, 1000);

  // You can use the moveTo and run functions to control the stepper motor
  stepper.moveTo(n);  // Move to position 1000
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }

  delay(50);  // Add a delay between movements

  n = random(0, 1000);

  stepper.moveTo(1000);  // Move back to the starting position
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }

  delay(50);  // Add a delay between movements

  digitalWrite(enblPin, HIGH); // Disable the motor
}