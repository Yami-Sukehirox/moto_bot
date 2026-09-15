#define EnA 10
#define EnB 5

#define In1 9
#define In2 8
#define In3 7
#define In4 6

#define TRIG 3
#define ECHO 4

void setup()
{
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);

  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}
long getDistance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);

  long distance = duration * 0.034 / 2;

  return distance;
}

void goStraight()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);

  analogWrite(EnA, 200);

  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);

  analogWrite(EnB, 200);
}
void setpMotors()
{
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}
void turnRight()
{
  digitalWrite(In1, HiGH);
  digitalWrite(In2, LOW);

  analogWrite(EnA, 200);

  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);

  analogWrite(EnB, 200);
}
void loop()
{
  long distance = getDistance();

  Serial.println(distance);

  if (distance > 20)
  {
    goStraight();
  }
  else 
  {
    void stopMotors();
    delay(500);

    turnRight();
    delay(800);
  }
}