/*
  SparkFun Inventor’s Kit
  Circuit 5A - Motor Basics

  Learn how to control one motor with the motor driver.

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

//PIN VARIABLES
//the motor will be controlled by the motor A pins on the motor driver
const int AIN1L = 13;           //control pin 1 on the motor driver for the right motor
const int AIN2L = 12;            //control pin 2 on the motor driver for the right motor
const int PWMAL = 11;            //speed control pin on the motor driver for the right motor
const int BIN1L = 10;
const int BIN2L = 9;
const int PWMBL = 8;
const int AIN1R = 7;
const int AIN2R = 6;
const int PWMAR = 5;
const int BIN1R = 4;
const int BIN2R = 3;
const int PWMBR = 2;

//int switchPin = 7;             //switch to turn the robot on and off

//VARIABLES
int motorSpeed=255;      //starting speed for the motor
//int ch=3;
void setup() {
  //pinMode(switchPin, INPUT_PULLUP);   //set this as a pullup to sense whether the switch is flipped

  //set the motor control pins as outputs
  pinMode(AIN1L, OUTPUT);
  pinMode(AIN2L, OUTPUT);
  pinMode(PWMAL, OUTPUT);
  pinMode(BIN1L, OUTPUT);
  pinMode(BIN2L, OUTPUT);
  pinMode(PWMBL, OUTPUT);
  pinMode(AIN1R, OUTPUT);
  pinMode(AIN2R, OUTPUT);
  pinMode(PWMAR, OUTPUT);
  pinMode(BIN1R, OUTPUT);
  pinMode(BIN2R, OUTPUT);
  pinMode(PWMBR, OUTPUT);




  Serial.begin(9600);                       //begin serial communication with the computer

  //Serial.println("Enter CHOICE (1,2,-1)... ");    //Prompt to get input in the serial monitor.
}

void loop() {

  //spinMotor();
   digitalWrite(AIN1L, HIGH);                         //set pin 1 to high
   digitalWrite(AIN2L, LOW);                          //set pin 2 to low
   digitalWrite(BIN1L, HIGH);                         
   digitalWrite(BIN2L, LOW);
   digitalWrite(AIN1R, HIGH);
   digitalWrite(AIN2R, LOW);
   digitalWrite(BIN1R, HIGH);
   digitalWrite(BIN2R, LOW);
   analogWrite(PWMAL, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
   analogWrite(PWMBL, abs(motorSpeed));  
   analogWrite(PWMAR, abs(motorSpeed));
   analogWrite(PWMBR, abs(motorSpeed));
    //Serial.println(" Straight ");
   delay(2000);
   digitalWrite(AIN1L, LOW);                         //set pin 1 to high
   digitalWrite(AIN2L, HIGH);                          //set pin 2 to low
   digitalWrite(BIN1L, LOW);                         
   digitalWrite(BIN2L, HIGH);
   digitalWrite(AIN1R, HIGH);
   digitalWrite(AIN2R, LOW);
   digitalWrite(BIN1R, HIGH);
   digitalWrite(BIN2R, LOW);
   analogWrite(PWMAL, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
   analogWrite(PWMBL, abs(motorSpeed));  
   analogWrite(PWMAR, abs(motorSpeed));
   analogWrite(PWMBR, abs(motorSpeed));
   delay(1500);
}

/********************************************************************************/
/*void spinMotor()                       //function for driving the right motor
{
    digitalWrite(AIN1L, HIGH);                         //set pin 1 to high
    digitalWrite(AIN2L, LOW);                          //set pin 2 to low
    digitalWrite(BIN1L, HIGH);                         
    digitalWrite(BIN2L, LOW);
    digitalWrite(AIN1R, HIGH);
    digitalWrite(AIN2R, LOW);
    digitalWrite(BIN1R, HIGH);
    digitalWrite(BIN2R, LOW);
    analogWrite(PWMAL, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
    analogWrite(PWMBL, abs(motorSpeed));  
    analogWrite(PWMAR, abs(motorSpeed));
    analogWrite(PWMBR, abs(motorSpeed));
    //Serial.println(" Straight ");
    delay(2000);
    analogWrite(PWMAL, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
    analogWrite(PWMBL, abs(motorSpeed));  
    analogWrite(PWMAR, abs(motorSpeed));
    analogWrite(PWMBR, abs(motorSpeed));
  
}*/
