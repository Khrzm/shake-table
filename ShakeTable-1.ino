#include <AccelStepper.h>

#define stepPin 6
#define dirPin 9
#define enblPin 12

AccelStepper stepper(AccelStepper::DRIVER, stepPin, dirPin);

void setup() {
  pinMode(enblPin, OUTPUT);
  digitalWrite(enblPin, LOW);

  Serial.begin(9600);
  Serial.println("init");

  delay(100);
  digitalWrite(enblPin, HIGH);

  // You can set additional parameters for your stepper motor here, such as max speed and acceleration
  stepper.setMaxSpeed(1000.0);
  stepper.setAcceleration(1000.0);
}

void loop() {
  // You can use the moveTo and run functions to control the stepper motor
  stepper.moveTo(1000);  // Move to position 1000
  stepper.run();

  delay(1000);  // Add a delay between movements

  stepper.moveTo(0);  // Move back to the starting position
  stepper.run();

  delay(1000);  // Add a delay between movements
}
