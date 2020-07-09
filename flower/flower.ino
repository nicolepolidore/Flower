#define TIMER_LENGTH 2000
#define TIMER_LENGTH_TWO 6000
#define BUG_DURATION 1200 //how long bugs will be there
#define BUG_DURATION_TWO 2500
enum gameStates {PETAL,  CENTER, BUG, BUG2};
byte gameState = PETAL;


Timer bugTimer;
Timer bugTimer2;

bool isPetal = false;
bool isCenter = false;
bool isAttacked = false;
bool isAttackedBig = false;
bool longPressing = false;

//byte bugLvl_One;
//byte bugLvl_Two;
//byte bugLvl_Three;

byte clicks = 1;

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

  case BUG2:
  bugTwoLoop();
  break;
  
  case CENTER:
   centerLoop();
   break;
  }
  
  displaySignalState();

  setValueSentOnAllFaces(gameState);
}

void petalLoop(){
  if(buttonLongPressed()){ //setting the center to yellow
    longPressing = true;
  
    gameState = CENTER;
  }
  if(buttonDown()|| buttonDoubleClicked()){ //reset the bug timer and bring it to petal gamestate
    bugTimer.set(TIMER_LENGTH);
    gameState = PETAL;
  }

  if(buttonDoubleClicked()){
    bugTimer2.set(TIMER_LENGTH_TWO);
    gameState = PETAL;
  }
  if(bugTimer.isExpired()){ 
    bugTimer.set(BUG_DURATION);
    isAttacked = true;
    gameState = BUG;
  }

  if(bugTimer2.isExpired()){
    bugTimer2.set(BUG_DURATION_TWO);
    isAttackedBig = true;
    gameState = BUG2;
  }
 
  
 
  }

void bugLoop(){

  if(isAttacked){ //attacking petal
    setColorOnFace(RED,1);
    if(buttonSingleClicked()){
      clicks = 1;
      gameState = PETAL;
    }
  }
  return;
  
  //here, I want to add petal health. 
  //once a petal dies, player must remove the blink
  //regrowth option? set aside a "butterfly" blink to regrow a petal. butterfly loses one health

  //I definetely want to add "stronger" bugs, meaning you have to click them 3 times in order to kill them
  
}

void bugTwoLoop(){
  if(isAttacked){ //attacking petal
    setColorOnFace(GREEN,4);
    setColorOnFace(GREEN,3);
    if(buttonDoubleClicked()){
       clicks =2;
       gameState = PETAL;
    }
   }
}

void centerLoop(){
  isCenter=true;
  setColor(YELLOW);
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
    
    case BUG2:
    bugTwoLoop();
    setColorOnFace(GREEN,4);
    setColorOnFace(GREEN,3);
    break;

   case CENTER:
   centerLoop();
   setColor(YELLOW);
   break;
    
  }
}
