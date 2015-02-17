#include <Arduino.h>
#include <SoftwareServo.h>

SoftwareServo myservo;


int buttonPin = 3; 
int buttonState = 0; 
int actionState=1;

void setup() 
{ 
  myservo.attach(1);  // attaches the servo on pin 2 to the servo object 
  myservo.write(0);
  pinMode(buttonPin, INPUT);
} 

void loop() { 
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
    if(actionState>=4){ 
    actionState=1;
    }
      switch(actionState){
        case 1:
        basicMotion();
        actionState+=1;
        break;
        case 2:
        slowMotion();
        actionState+=1;
        break;
        case 3:
        angryMotion();
        actionState+=1;
        break;
      } 
  } 
   else{
      myservo.write(0);
    //check that button is off
  }
  SoftwareServo::refresh();
}


void basicMotion(){
 for(int pos = 0; pos < 100; pos += 1)  
    {                                 
    myservo.write(pos);              
    delay(15);                       
    SoftwareServo::refresh();
    } 
}
    
//This is super funny really slow motion out
void slowMotion(){ 
 for(int pos = 0; pos < 100; pos += 1)  
    {                                 
    myservo.write(pos);              
    delay(50);                       
    SoftwareServo::refresh();
    } 
}
    
//This is the angry wiggle and then regular switch off
void angryMotion(){
for( int i = 0; i <10;i+=1){
      for(int pos = 30; pos < 60; pos += 5)  
      {                                 
      myservo.write(pos);              
      delay(15);                       
      SoftwareServo::refresh();
      }
    } 
    for(int pos = 60; pos < 100; pos += 1)  {                                 
      myservo.write(pos);              
      delay(15);                       
      SoftwareServo::refresh();
      }
}  

/*This ont kinda test you with some teaser hits and then goes for it
for( int i = 0; i <5;i+=1){
      for(int pos = 50; pos < 80; pos += 1)  
      {                                 
      myservo.write(pos);              
      delay(15);                       
      SoftwareServo::refresh();
      } 
    }
    for(int pos = 70; pos < 100; pos += 1)  
      {                                 
      myservo.write(pos);              
      delay(15);                       
      SoftwareServo::refresh();
      }    
  } 
*/
