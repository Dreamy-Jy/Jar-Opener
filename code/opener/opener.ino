const int ENB = 10;
const int IN4 = 8;
const int IN3 = 7;
const int BUT = 4;

const int MOTOR_SPEED = 200;
const int MOTOR_STOP = 0;
bool is_running = false;
bool is_pressed = false;

unsigned long cycle_start;
const unsigned long CYCLE_TIME = 2000;

void setup() {
  pinMode(ENB, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(BUT, INPUT);

  // Set Motor Direction
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  analogWrite(ENB, MOTOR_STOP);
}

void loop() {
  is_pressed = (digitalRead(BUT) == HIGH) ? true : false;

  if (!is_running && is_pressed) {
    is_running = true;
    start = millis();
    analogWrite(ENB, MOTOR_SPEED);
  }

  if (is_running && millis() - cycle_start >= CYCLE_TIME) {
    is_running = false;
    analogWrite(ENB, MOTOR_STOP);
  }

}
