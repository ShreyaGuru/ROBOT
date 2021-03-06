// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
// This sketch is a good place to start if you're just getting started with 
// Pixy and Arduino.  This program simply prints the detected object blocks 
// (including color codes) through the serial console.  It uses the Arduino's 
// ICSP SPI port.  For more information go here:
//
// https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:hooking_up_pixy_to_a_microcontroller_-28like_an_arduino-29
//
  
#include <Pixy2.h>
#include <math.h> 
// This is the main Pixy object
Pixy2 pixy;
int X,Y;
float angle, theta;

int motorSpeed=200;

const int AIN1L = 42;           //control pin 1 on the motor driver for the right motor
const int AIN2L = 40;            //control pin 2 on the motor driver for the right motor
const int PWMAL = 13;            
const int BIN1L = 36;
const int BIN2L = 38;
const int PWMBL = 11;
const int AIN1R = 45;
const int AIN2R = 47;
const int PWMAR = 7;
const int BIN1R = 46;
const int BIN2R = 44;
const int PWMBR = 4;
void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  pixy.init();
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
}
 
void loop()
{ 
  int i; 
  // grab blocks!
  pixy.ccc.getBlocks();
  
  // If there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    Serial.print("Detected ");
    Serial.println(pixy.ccc.numBlocks);
    X = pixy.ccc.blocks[i].m_x;
    Y = pixy.ccc.blocks[i].m_y;
    for (i=0; i<pixy.ccc.numBlocks; i++)
    {
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      //pixy.ccc.blocks[i].print();
      angle=atan((157.5 - X)/(103.5 - Y));
      theta=angle*57;
      Serial.println(theta);
      
      if (theta>10){
      Serial.println(" GREEN ");
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
      delay(50); 
      }
      else if (theta<-10)
      {
      Serial.println(" RED "); 
      digitalWrite(AIN1L, LOW);                         //set pin 1 to high
      digitalWrite(AIN2L, HIGH);                          //set pin 2 to low
      digitalWrite(BIN1L, LOW);                         
      digitalWrite(BIN2L, HIGH);
      digitalWrite(AIN1R, LOW);
      digitalWrite(AIN2R, HIGH);
      digitalWrite(BIN1R, LOW);
      digitalWrite(BIN2R, HIGH);
      analogWrite(PWMAL, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
      analogWrite(PWMBL, abs(motorSpeed));  
      analogWrite(PWMAR, abs(motorSpeed));
      analogWrite(PWMBR, abs(motorSpeed));
      delay(50);  
      }
      /*else{
      digitalWrite(AIN1L, HIGH);                         //set pin 1 to high
      digitalWrite(AIN2L, LOW);                          //set pin 2 to low
      digitalWrite(BIN1L, HIGH);                         
      digitalWrite(BIN2L, LOW); 
      digitalWrite(AIN1R, HIGH);
      digitalWrite(AIN2R, LOW);
      digitalWrite(BIN1R, HIGH);
      digitalWrite(BIN2R, LOW);
      analogWrite(PWMAL, 0);                 //now that the motor direction is set, drive it at the entered speed
      analogWrite(PWMBL, 0);  
      analogWrite(PWMAR, 0);
      analogWrite(PWMBR, 0); 
      delay(50); 
      }*/
    }
  }  
}
