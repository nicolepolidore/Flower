#define TIMER_LENGTH 2000
#define BUG_DURATION 1200 //how long bugs will be there
enum gameStates {PETAL,  CENTER, BUG};
byte gameState = PETAL;


Timer bugTimer;

bool isPetal = false;
bool isCenter = false;
bool isAttacked = false;

void setup(){
}

void loop(){

   switch(gameState){
    
  case PETAL: 
    petalLoop();
    break;
    
  case BUG:
  bugLoop();
  break;
  
  case CENTER:
   centerLoop();
   break;
  }
  
  displaySignalState();

  setValueSentOnAllFaces(gameState);
}

void petalLoop(){
  if(buttonDoubleClicked()){ //setting the center to yellow
    gameState = CENTER;
  }
  if(buttonDown()){ //reset the bug timer and bring it to petal gamestate
    bugTimer.set(TIMER_LENGTH);
    gameState = PETAL;
  }
  if(bugTimer.isExpired()){ 
    bugTimer.set(BUG_DURATION);
    isAttacked = true;
    gameState = BUG;
  }
  
 
  }

void bugLoop(){

  if(isAttacked){ //attacking petal
    setColorOnFace(RED,1);
    if(buttonDown()){
      gameState = PETAL;
    }
  }
  return;
  
  //here, I want to add petal health. 
  //once a petal dies, player must remove the blink
  //regrowth option? set aside a "butterfly" blink to regrow a petal. butterfly loses one health

  //I definetely want to add "stronger" bugs, meaning you have to click them 3 times in order to kill them
  
}

void centerLoop(){
  isCenter=true;
  gameState=CENTER;
  
 
}

void displaySignalState(){
  switch(gameState){
    case PETAL:
    petalLoop();
    setColor(CYAN);
    break;

    case BUG:
    bugLoop();
    setColorOnFace(RED,1);
    break;

   case CENTER:
   centerLoop();
   setColor(YELLOW);
   break;
    
  }
}
