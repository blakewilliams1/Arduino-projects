#include <Servo.h>

//use bottom right 2 pins on button switch, where one is
//is connected to 5V, and the other to analog 0

//for servo, connect data to pin 9

Servo myservo;  
int pos = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("ready");
  pinMode(10,INPUT);
  myservo.attach(9);
}

int maxPos = 180;
int currPos = maxPos;
int minPos = 55;
void loop() {
  delay(300);
  if(analogRead(0)>1000){
    while(currPos > minPos) {
      currPos -= 3;
      myservo.write(currPos);              
      delay(15);                      
    }
    //button has been pressed. now retract servo
    while(currPos < maxPos) {
      currPos += 3;
      myservo.write(currPos);              
      delay(15);                      
    }
  }
  
  constrain(currPos,minPos,maxPos);
  myservo.write(currPos);
}





