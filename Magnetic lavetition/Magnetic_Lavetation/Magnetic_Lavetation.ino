const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < 20) {
    int frequency = map(distance, 0, 20, 2000, 500);
    tone(buzzerPin, frequency, 500);
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else {
    noTone(buzzerPin);
  }
  
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
