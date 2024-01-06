int pulPin = 6;
int dirPin = 9;
int enblPin = 12;

long loops = 0;
int direction = 1; // 1 for forward, -1 for reverse
long targetLoops = 0; // target number of loops for each movement

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

  randomSeed(analogRead(0)); // initialize random number generator
}

void loop() {
  if (loops == targetLoops) {
    direction = -direction; // reverse direction
    targetLoops = loops + direction * random(1, 1001); // set a new target
    if (targetLoops > 1000) targetLoops = 1000;
    if (targetLoops < -1000) targetLoops = -1000;
    delay(250); // n seconds delay
  }

  digitalWrite(dirPin, direction == 1 ? LOW : HIGH);
  digitalWrite(pulPin, HIGH);
  digitalWrite(pulPin, LOW);
  loops += direction;
  delay(1);
}