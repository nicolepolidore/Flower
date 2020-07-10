#define TIMER_LENGTH 2000
#define WAIT_TIMER 2000
#define BUG_DURATION 1200 //how long bugs will be there

//one timer and needs to say a wait timer
//every time a bug is sqaushed do isAttacked
//void spawn bug and kill bug

enum gameStates {PETAL,  CENTER, BUG, BUG2};
byte gameState = PETAL;


Timer bugTimer;
Timer waitTimer;


bool isPetal = false;
bool isCenter = false;
bool isAttacked = false;
bool longPressing = false;

byte bugLvl = 0;

byte clicks = 1;

void setup(){
  bugTimer.set(TIMER_LENGTH);
  waitTimer.set(WAIT_TIMER);
  randomize(); 
}

void loop(){
  
  if(buttonLongPressed()){ //setting the center to yellow
    longPressing = true;
    gameState = CENTER;
  }


   switch(gameState){
    
  case PETAL: 
    petalLoop();
    break;
    
  case BUG:
  bugLvl =1;
  killBug();
  break;

  case BUG2:
  bugLvl=2;
 killBug();
  break;
  
  case CENTER:
   centerLoop();
   break;
  }
  buttonLongPressed();
  
  displaySignalState();

  setValueSentOnAllFaces(gameState);
}

void petalLoop(){

  
//  if(bugTimer.isExpired()){
//    spawnBug();
//  }
//  
  if(waitTimer.isExpired()){
    spawnBug();
  }
  
}
  
  //here, I want to add petal health. 
  //once a petal dies, player must remove the blink
  //regrowth option? set aside a "butterfly" blink to regrow a petal. butterfly loses one health

  //I definetely want to add "stronger" bugs, meaning you have to click them 3 times in order to kill them
  
void spawnBug(){


if (random(1) == 0) {
    bugLvl = 2;
    gameState = BUG2;
  } else {
    bugLvl = 1;
    gameState = BUG;
  }


}




void killBug(){
  if(buttonSingleClicked()){
    bugLvl =1 ;
    clicks =1;
    isAttacked = true;
    gameState = PETAL;
    waitTimer.set(WAIT_TIMER);
  }
  
  if(buttonDoubleClicked()){
     gameState= PETAL;
     bugLvl=2;
     clicks = 2;
    isAttacked = true;
    waitTimer.set(WAIT_TIMER);
    
  } 
  return;
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
    bugLvl=1;
    killBug();
    setColorOnFace(RED,1);
    break;
    
    case BUG2:
    bugLvl= 2;
    killBug();
    setColorOnFace(GREEN,4);
    setColorOnFace(GREEN,3);
    break;

   case CENTER:
   centerLoop();
   setColor(YELLOW);
   break;
    
  }
}
