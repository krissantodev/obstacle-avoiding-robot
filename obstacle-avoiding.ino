#include <Servo.h>

const int trigPin = 5;
const int echoPin = 4;

int IN1 = 12;
int IN2 = 13;
int IN3 = 7;
int IN4 = 6;
int ENA = 11;
int ENB = 3;
int speed = 155;
int Servopin = 8;

long duration;
int distance;

Servo myServo;

void stopMotor() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// Function to get distance from sensor
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  stopMotor();
  
  myServo.attach(Servopin);
  myServo.write(90);
  delay(500);  // Give servo time to reach position
}

void loop() {
  // Look forward
  myServo.write(90);
  delay(500);  // IMPORTANT: Wait for servo to move
  
  int centerDistance = getDistance();
  Serial.print("Center: ");
  Serial.println(centerDistance);

  if (centerDistance <= 30 && centerDistance > 0) {  // Added > 0 check
    stopMotor();
    delay(100);
    
    // Look LEFT (0 degrees)
    myServo.write(0);
    delay(300);  // Wait for servo to move
    
    int leftDistance = getDistance();
    Serial.print("Left: ");
    Serial.println(leftDistance);
    
    // Look RIGHT (180 degrees)
    myServo.write(180);
    delay(800);  // Wait for servo to move
    
    int rightDistance = getDistance();
    Serial.print("Right: ");
    Serial.println(rightDistance);
    
    // Decision making
    if (leftDistance > rightDistance) {
      Serial.println("GO RIGHT (more space)");
      delay(350);
      myServo.write(90);
      delay(150);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 155);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, 155);
      // Add turning left code here
    } else if (rightDistance > leftDistance) {
      Serial.println("GO LEFT (more space)");
      delay(350);
      myServo.write(90);
      delay(150);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, 155);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, 155);
    } else {
      Serial.println("GO BACK (same distance)");
    }
    
  }
  else {
    // Move forward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speed);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speed);
  }
  
  delay(500);
}
