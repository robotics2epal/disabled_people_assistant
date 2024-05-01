#include <Servo.h>

Servo left_servo;  // create servo object to control a servo
Servo right_servo;  // create servo object to control a servo


byte com = 0;
int pos = 0;    // variable to store the servo position


void setup() {

    left_servo.attach(9);  // attaches the servo on pin 9 to the servo object
    right_servo.attach(10);  // attaches the servo on pin 9 to the servo object
    left_servo.write(100);              // tell servo to go to position in variable 'pos'
    right_servo.write(0);              // tell servo to go to position in variable 'pos'

	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);
      
    delay(2000);                  

  
Serial.begin(9600);

Serial.write(0xAA);

Serial.write(0x37);

delay(1000);

Serial.write(0xAA);

Serial.write(0x21);




}

void loop() {

  while(Serial.available()) {

  com = Serial.read();

  switch(com) {

      case 0x11:   //command 1 is for Green LED 

      
		  for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
			// in steps of 1 degree
			right_servo.write(pos);              // tell servo to go to position in variable 'pos'
			left_servo.write(100-pos);              // tell servo to go to position in variable 'pos'
			delay(15);                       // waits 15ms for the servo to reach the position
		  }

      break;

      case 0x12:  //command 2 is for Red LED

		  for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
			right_servo.write(pos);              // tell servo to go to position in variable 'pos'
			 left_servo.write(100-pos);              // tell servo to go to position in variable 'pos'
		   delay(15);                       // waits 15ms for the servo to reach the position
		  }

      break;

      case 0x13:  //command 3 is for Yellow LED

			digitalWrite(13, HIGH);
			delay(3000);
			digitalWrite(13, LOW);
      break;

      case 0x14:  //command 4 is for Servo motor


      break;

      case 0x15:  //command 5 is for Servo Motor
      


      break;

            }
      }
}
