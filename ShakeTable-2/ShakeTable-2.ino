int pulPin = 6;
int dirPin = 9;
int enblPin = 12;

long loops = 0;
int direction = 1; // 1 for forward, -1 for reverse

void setup() {
  pinMode(pulPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enblPin, OUTPUT);

  digitalWrite(pulPin, LOW);
  digitalWrite(enblPin, LOW);
  digitalWrite(dirPin, HIGH);

  Serial.begin(9600);
  Serial.println("init");

  digitalWrite(enblPin, HIGH);
  delay(100);
  digitalWrite(enblPin, LOW);
}

void loop() {
  while ((loops < 1000 && direction == 1) || (loops > -1000 && direction == -1)) {
    digitalWrite(dirPin, direction == 1 ? LOW : HIGH);
    digitalWrite(pulPin, HIGH);
    digitalWrite(pulPin, LOW);
    loops += direction;
    delay(1);

    if (loops == 1000 && direction == 1) {
      direction = -1; // reverse direction
      delay(250); // n seconds delay
    } else if (loops == -1000 && direction == -1) {
      direction = 1; // forward direction
      delay(250); // n seconds delay
    }
  }
}