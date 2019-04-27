/*
* NOSCH- No spill cup holder
* 
* Testing one dimensional anti motion using ADXL-335 and Servo
* 
* by Gowtham Tummala and Ankita Acharya
* 
*/


const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis (only on 3-axis models)
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int x_val;
int prev_val;
int anti_pos;

void setup() {
    Serial.begin(9600); // initialize the serial communications:
    myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  }

void loop() {
  x_val  = analogRead(xpin); // print the sensor values:
  Serial.print(x_val);
  Serial.print("\t");   // print a tab between values:
  //Serial.print(analogRead(ypin));
  //print a tab between values:
  //Serial.print("\t");
  //Serial.print(analogRead(zpin));
  //Serial.println();
  // delay before next reading:
  pos = x_val * 180 / 148 +95; // position valus for accelerometer output values

//minimize large variations
  if(abs(pos - prev_val) > 20){
    pos = prev_val;
  }
  
  Serial.print(pos);
  Serial.print("\t");
  anti_pos = 180 - pos; // giving opposite motion for servo
  Serial.print(anti_pos);
  myservo.write(anti_pos);
  Serial.println();
  prev_val = pos; 
  delay(1);
}
