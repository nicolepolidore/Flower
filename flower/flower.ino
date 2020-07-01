#define TIMER_LENGTH 2000
enum signalStates {PETAL,  CENTER};
byte signalState = PETAL;


Timer centerTimer;

bool isPetal = false;
bool isCenter = false;

void setup(){
  centerTimer.set(TIMER_LENGTH);
}

void loop(){

   switch(signalState){
    
  case PETAL:
    petalLoop();
    break;

  case CENTER:
   centerLoop();
   break;
  }
  
  displaySignalState();

  setValueSentOnAllFaces(signalState);
}

void petalLoop(){
  if(buttonDoubleClicked()){
    isPetal = false;
    signalState = CENTER;
  }
  if(buttonDown()){
    isPetal = true;
  }
}

void centerLoop(){
  if(centerTimer.isExpired()){
    setColorOnFace(RED,1);
  }else{
    setColor(CYAN);
  }
}

void displaySignalState(){
  switch(signalState){
    case PETAL:
    petalLoop();
    setColor(CYAN);
    break;

   case CENTER:
   centerLoop();
   setColor(YELLOW);
   break;
    
  }
}
