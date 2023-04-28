#include <Keypad.h>
#include "StepperMotor.h"
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 10, 11, 12, 13);
char*password = "1234";
int pozisyon = 0;
const byte rows = 4; //four rows
const byte cols = 4; //four columns
//define the cymbols on the buttons of the keypads
char keyMap [rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
byte rowPins[rows] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[cols] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, rows, cols); 

void setup(){
  Serial.begin(9600);
  myStepper.setSpeed(60);
}
  
void loop(){
 Serial.println();
  char whichKey = myKeypad.getKey(); //define which key is pressed with getKey
  Serial.println(whichKey); 


  if(whichKey == '*' || whichKey == '#' || whichKey == 'A' ||       //define invalid keys
  whichKey == 'B' || whichKey == 'C' || whichKey == 'D'){

    pozisyon=0;
    setLocked (true);
   
  }
  if(whichKey == password [pozisyon]){

    pozisyon ++;
  }
  if(pozisyon == 4){
    setLocked (false);
   
  }
  delay(100);
}
void setLocked(int locked){
  if(locked){
   Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);
  }
  else{
     Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
  }
  }
