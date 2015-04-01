#include <SoftwareSerial.h>

const char UP = 1;
const char DOWN = 2;
const char LEFT = 3;
const char RIGHT = 4;
const char SHOOT = 5;


const int blueTx = 2; //bluetooth Setting
const int blueRx = 3; //bluetooth Setting

const int buttonPin2 = 4;     // the number of the pushbutton pin
const int buttonPin3 = 5;     // the number of the pushbutton pin
const int buttonPin4 = 6;     // the number of the pushbutton pin
const int buttonPin5 = 7;     // the number of the pushbutton pin
const int buttonPin6 = 8;     // the number of the pushbutton pin



// variables will change:

int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;         // variable for reading the pushbutton status
int buttonState4 = 0;         // variable for reading the pushbutton status
int buttonState5 = 0;         // variable for reading the pushbutton status
int buttonState6 = 0;         // variable for reading the pushbutton status
int oldButtonState2 = 0;         // variable for reading the pushbutton status
int oldButtonState3 = 0;         // variable for reading the pushbutton status
int oldButtonState4 = 0;         // variable for reading the pushbutton status
int oldButtonState5 = 0;         // variable for reading the pushbutton status
int oldButtonState6 = 0;         // variable for reading the pushbutton status



SoftwareSerial mySerial(blueTx,blueRx);
String myString = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  
  // initialize the LED pin as an output:
//  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);  
  // initialize the LED pin as an output:
//  pinMode(ledPin3, OUTPUT);
  // initialize the pushbutton pin as an input:


}

void loop() {
  // read the state of the pushbutton value:
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);  
  oldButtonState2 =  buttonRead(oldButtonState2,  buttonState2 , UP);
  oldButtonState3 =  buttonRead(oldButtonState3,  buttonState3 , DOWN);
  oldButtonState4 =  buttonRead(oldButtonState4,  buttonState4 , LEFT);
  oldButtonState5 =  buttonRead(oldButtonState5,  buttonState5 , RIGHT);
  oldButtonState6 =  buttonRead(oldButtonState6,  buttonState6 , SHOOT);  
  // put your main code here, to run repeatedly:
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
}
int buttonRead(int oldState ,int curState, char buttonKind){ //return oldState for change
  boolean isActionChange = false;
  boolean upperCase = false;
    if(curState == HIGH){
    if (curState != oldState){
      if(!oldState){
//        digitalWrite(ledPin2, HIGH);
        isActionChange = true;
        upperCase = true;
        oldState = curState;
      }
    }
  }else{
    if (curState != oldState){
      if(oldState){
//        digitalWrite(ledPin2, LOW);
        isActionChange = true;
        upperCase = false;
        oldState = curState;
      }
    }  
  }
  serialWrite(isActionChange , upperCase , buttonKind);
  return oldState;
}

void   serialWrite(boolean isActionChange , boolean upperCase , char buttonKind){
  
  if(isActionChange)
    if(upperCase)
      switch(buttonKind){
        case UP : 
        mySerial.write("U");
        Serial.write("U");
        break;
        case DOWN : 
        mySerial.write("D");
        Serial.write("D");
        break;
        case LEFT : 
        mySerial.write("L");
        Serial.write("L");
        break;
        case RIGHT : 
        mySerial.write("R");
        Serial.write("R");
        break;
        case SHOOT : 
        mySerial.write("S");
        Serial.write("S");
        break;
      }
     else
      switch(buttonKind){
        case UP : 
        mySerial.write("u");
        Serial.write("u");
        break;
        case DOWN : 
        mySerial.write("d");
        Serial.write("d");
        break;
        case LEFT : 
        mySerial.write("l");
        Serial.write("l");
        break;
        case RIGHT : 
        mySerial.write("r");
        Serial.write("r");
        break;
        case SHOOT : 
        mySerial.write("s");
        Serial.write("s");
        break;
      }
}


