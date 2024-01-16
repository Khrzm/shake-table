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
  stepper.setMaxSpeed(20000.0);
  stepper.setAcceleration(20000.0);
}

void loop() {
  digitalWrite(enblPin, LOW); // Enable the motor

  stepper.moveTo(00);  // Move back to the position
  //stepper.moveTo(-1000);  // Move back to the position
  //stepper.moveTo(1000);  // Move forward to the position
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  
  delay(1000);  // Add a delay between movements

  digitalWrite(enblPin, HIGH); // Disable the motor
}