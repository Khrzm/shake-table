#define dirPin 9
#define stepPin 6

void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(stepPin, HIGH);
  delay(500);
  digitalWrite(stepPin, LOW);
  delay(500);
}
