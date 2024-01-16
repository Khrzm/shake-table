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

  // Initialize random number generator
  randomSeed(analogRead(0));
}

void loop() {
  digitalWrite(enblPin, LOW); // Enable the motor

  int currentPosition = stepper.currentPosition();
  int randomOffset = random(-1000, 1000);  // Generate a random offset within the range -1000 to 1000
  int newPosition = currentPosition + randomOffset;  // Calculate the new position

  // Ensure the new position is within the range -3000 to 3000
  newPosition = max(-1001, min(1001, newPosition));

  stepper.moveTo(newPosition);  // Move to the new position
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  
  delay(100);  // Add a delay between movements

  digitalWrite(enblPin, HIGH); // Disable the motor
}