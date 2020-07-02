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
    
  case PETAL: //petal is really game state
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
  int timeProgress = millis() % TIMER_LENGTH;
  
  if(!centerTimer.isExpired()){ //if timer is expired
    int timeProgress = centerTimer.getRemaining();
  }
      setColorOnFace(RED,1);

  if(buttonDown()){
    setColor(CYAN);
  }
//  FOREACH_FACE(f){
//      if(!isValueReceivedOnFaceExpired(f)){
//
//        byte neighbor = getLastValueReceivedOnFace(f);
//
//        if(neighbor == buttonDown()){
//          setColor(CYAN);
//        }
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
