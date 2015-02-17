// Idea Box

#include <Servo.h> 

Servo myservo;

int pos = 0;
int buttonPin = 8; 
int servoPin = 9;
int buttonState = 0; 
int i=1; //First iteration of interactionType then turned on
// By making the switch position and peak-out positions variables
// we can try different interactions without having everything 
// hardcoded
int switchPos = 90; 
int peakPos = 20;
int homePos = 0;



void setup() 
{ 
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 
  pinMode(buttonPin, INPUT);
} 

void loop(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
    myservo.write(90);
    delay(20);
   
  }
    else{
      myservo.write(0);
    //check that button is off
  }
  
}

void interactionType(int intnum){
 switch(intnum){
   case 1: // Regular switch off
     myservo.write(switchPos);
     
     break;
   case 2:
     myservo.write(peakPos);
     delay(50);
     myservo.write(homePos);
     delay(50);
 }  
}


  
  
    
