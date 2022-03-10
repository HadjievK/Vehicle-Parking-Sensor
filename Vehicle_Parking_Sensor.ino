// defines pins numbers
#define IN4  4
const int trigPin = 5;
const int echoPin = 6;
// defines variables
long duration;
int distance = 0;
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  if ((distance <= 30) && (distance > 0))
  {
    digitalWrite(IN4, HIGH);
  }
  else if ((distance > 31) && (distance <= 80)){
    digitalWrite(IN4, HIGH);
    delay(10 * (distance - 30));
    digitalWrite(IN4, LOW);
    delay(10 * (distance - 30));
    delay(50);
  }
  else if ((distance > 81) && (distance < 110)) {
    digitalWrite(IN4, HIGH);
    delay(500);
    digitalWrite(IN4, LOW);
    delay(500);
  }
  else if (distance > 111){
    digitalWrite(IN4, LOW);

  }
  delayMicroseconds(10);
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print('\n');
  Serial.print(distance);
   Serial.print('\n');
}
