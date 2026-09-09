# Obstacle Avoiding Robot

An obstacle avoiding robot made using an Arduino Uno and Ultrasonic sensor + servo combination to decide the steer.

The robot works by running a reactive program by detecting distance, when the robot runs and the ultrasonic sensor reaches a set distance, it stops and evaluate. The servo helps the Ultrasonic sensor by turning the sensor left and right, thus taking the data of the distance from left and right. After taking the data, the distances are evaluated to see which path is the most optimal one.

## Components used
- Arduino Uno R3(Although this is interchangeable if you know what you're doing)
- SG90 Servo
- HC-SR04 Ultrasonic Sensor(again this is interchangeable)
- 4x DC motors
- 4x Gearbox(optional)
- L298N Motor Driver(interchangeable depending on your needs)
- A chassis kit(or you can 3D print them but I personally didn't)
- A step down buck converter(Optional but I used them for my servos)
- 2x 18650 Batteries(interchangeable with LiPo batteries or a far more powerful battery if you know what you're doing)
- 2 Battery holder

### **Note: The Servo.h library disables pin 9 and 10 for PWM uses. Configure the pins however you want but mind these restrictions.***

The pin configurations in the code are interchangeable on
- Supersonic  = line 3 & 4
- DC motor = line 6-12
- Servo = line 53

