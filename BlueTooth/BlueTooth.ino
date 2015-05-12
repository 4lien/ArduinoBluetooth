
const char UP = 1;
const char DOWN = 2;
const char LEFT = 3;
const char RIGHT = 4;
const char SHOOT = 5;
const char JUMP = 6;

const int VERT = 7; // analog
const int HORIZ = 6; // analog
const int SEL = 12; // digital
const int SHOOTButton = 11; // digital


// variables will change:

int VERTbuttonState = 0;         // variable for reading the pushbutton status
int HORIZbuttonState = 0;         // variable for reading the pushbutton status
int SELbuttonState = 0;         // variable for reading the pushbutton status
int SHOOTbuttonState = 0;         // variable for reading the pushbutton status

int VERTbuttonStateOld = 0;         // variable for reading the pushbutton status
int HORIZbuttonStateOld = 0;         // variable for reading the pushbutton status
int SELbuttonStateOld = 0;         // variable for reading the pushbutton status
int SHOOTbuttonStateOld = 0;         // variable for reading the pushbutton status



String myString = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(SEL,INPUT_PULLUP);    // 버튼 핀을 읽기 모드로 
  pinMode(SHOOTButton,INPUT_PULLUP);    // 버튼 핀을 읽기 모드로 
  
}

void loop() {
  // read the state of the pushbutton value:
  
  VERTbuttonState = (analogRead(VERT)+50)/100; // will be 0-1023
  HORIZbuttonState = (analogRead(HORIZ)+50)/100; // will be 0-1023
  VERTbuttonState = VERTbuttonState,DEC;
  SELbuttonState = digitalRead(SEL);
  SHOOTbuttonState = digitalRead(SHOOTButton);
  
  
  HORIZbuttonState = HORIZbuttonState < 3 ? -1 : HORIZbuttonState;
  HORIZbuttonState = HORIZbuttonState > 7 ? 1 : HORIZbuttonState;
  HORIZbuttonState = HORIZbuttonState > 1 ? 0 : HORIZbuttonState;
  
  
  VERTbuttonState = VERTbuttonState < 3 ? -1 : VERTbuttonState;
  VERTbuttonState = VERTbuttonState > 7 ? 1 : VERTbuttonState;
  VERTbuttonState = VERTbuttonState > 1 ? 0 : VERTbuttonState;
  
  
  SELbuttonStateOld = buttonRead(SELbuttonStateOld ,SELbuttonState, JUMP);
  SHOOTbuttonStateOld = buttonRead(SHOOTbuttonStateOld ,SHOOTbuttonState, SHOOT);
  
  
  if(VERTbuttonStateOld != VERTbuttonState)
      switch(VERTbuttonState){
        case -1 :
        Serial.print("K");
        Serial.print("r");
        break;
        case 1 :
        Serial.print("k");
        Serial.print("R"); 
        
        break;
        case 0 :
        Serial.print("k");
        Serial.print("r");
        break;
      }
      
  if(HORIZbuttonStateOld != HORIZbuttonState)
      switch(HORIZbuttonState){
        case -1 :
        Serial.print("Q");
        Serial.print("x");
        break;
        case 1 :
        Serial.print("X");
        Serial.print("q");
        break;
        case 0 :
        Serial.print("x");
        Serial.print("q");
        break;
      }
      
      HORIZbuttonStateOld = HORIZbuttonState;
      VERTbuttonStateOld = VERTbuttonState;
  
}

int buttonRead(int oldState ,int curState, char buttonKind){ //return oldState for change
  boolean isActionChange = false;
  boolean upperCase = false;
    if(curState == HIGH){
    if (curState != oldState){
      if(!oldState){
        isActionChange = true;
        upperCase = true;
        oldState = curState;
      }
    }
  }else{
    if (curState != oldState){
      if(oldState){
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
        case SHOOT :
        Serial.print("s");
        break;
        case JUMP : 
        Serial.print("j");
        break;
      }
     else
      switch(buttonKind){
        case SHOOT :
        Serial.print("S");
        break;
        case JUMP : 
        Serial.print("J");
        break;
      }
}



