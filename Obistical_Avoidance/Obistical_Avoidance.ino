
#include <NewPing.h> 
#include <Servo.h>
#define TRIG_PIN A1 
#define ECHO_PIN A0 
#define MAX_DISTANCE 200 
#define MAX_SPEED 150 
#define MAX_SPEED_OFFSET 20
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
Servo myservo;  
#define motorInput1 8
#define motorInput2 9 
#define motorInput3 10 
#define motorInput4 11
#define ena 5
#define enb 3

boolean goesForward=false;
int distance = 100;
int speedSet = 0;



void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:
  pinMode(motorInput1,OUTPUT);
  pinMode(motorInput2,OUTPUT);
  pinMode(motorInput3,OUTPUT);
  pinMode(motorInput4,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  
  myservo.attach(6);  
  myservo.write(250); 
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

}

void loop() {
Serial.println(distance);
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 
 if(distance<=40)
 {
  Stop();
  delay(100);
  moveBackward();
  delay(300);
  Stop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    turnRight();
    Stop();
  }else
  {
    turnLeft();
    Stop();
  }
 }else
 {
  moveForward();
 }
 distance = readPing();

}

int lookRight()
{
    myservo.write(50); 
    delay(200);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}

int lookLeft()
{
    myservo.write(170); 
    delay(200);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void Stop() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}

 void moveForward() {

 if(!goesForward)
  {
    goesForward=true;
    digitalWrite(motorInput1, HIGH);
    digitalWrite(motorInput2, LOW);
    digitalWrite(motorInput3, HIGH);
    digitalWrite(motorInput4, LOW);
    analogWrite(ena,120);
    analogWrite(enb,120); 
  /* for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
   {
    analogWrite(ena,speedSet);
    analogWrite(enb,speedSet);
    delay(5);
   }*/
  }
}

void moveBackward() {
    goesForward=false;
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, HIGH);
    digitalWrite(motorInput3, LOW);
    digitalWrite(motorInput4, HIGH); 
    analogWrite(ena,120);
    analogWrite(enb,120);
    
 /* for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
  {
    analogWrite(ena,speedSet);
    analogWrite(enb,speedSet);
    delay(5);
  }*/
}  

void turnRight() {
  analogWrite(ena,120);
  analogWrite(enb,120);
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH); 
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);  
  delay(450);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);  
} 
 
void turnLeft() {
  analogWrite(ena,120);
  analogWrite(enb,120);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH); 
  delay(450);
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);  

}  
  
