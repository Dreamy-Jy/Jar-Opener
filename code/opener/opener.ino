const int ENB = 10;
const int IN4 = 8;
const int IN3 = 7;

const int BUT = 4;

bool motion = true;

void setup() {
  pinMode(ENB, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(BUT, INPUT);

  // set inital Direction
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  analogWrite(ENB, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BUT) == HIGH) {
    analogWrite(ENB, 255);
  } else {
    analogWrite(ENB, 0);
  }
}
