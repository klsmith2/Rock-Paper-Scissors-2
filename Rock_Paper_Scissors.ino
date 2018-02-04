/* Rock-Paper-Scissors
 * By Kaye Smith
 
 * Two player game using push butons for input
 * Directions:  The LEDs will begin to blink - red three times, yellow three times, green three times
 * While the LEDs blink - make your choice
 * When the blinking ends push the button corresponding to your choice and hold until the green lights flash
 * Then release your button
 * Each players choice will be displayed - red=rock, yellow=paper, green=scissors
 * Result displayed - winner=one side flashes, tie=one color flashes, error=all flash
*/

//declare pins for the LEDs
//LEDs for Player 2 
int pin10 = 10; //green2
int pin9 = 9; //yellow2
int pin8 = 8; //red2

//LEDs for Player 1
int pin7 = 7; //red1
int pin6 = 6; //yellow1
int pin5 = 5; //green1

boolean ledState = LOW;   
int counter = 0;
int gameState = 0; // 0 = LEDs blinking / game play
              //  1 = results

//declare pins for buttons
// Buttons for Player 2
int pin13 = 13; //scissors 2
int pin12 = 12; //paper 2
int pin11 = 11; //rock 2

// Buttons for Player 1
int pin4 = 4; //rock 2
int pin3 = 3; //paper 2
int pin2 = 2; //scissors 2


// Program variables for each player
int rockVal1 = 0;   // Variables to store the values from the buttons player 1
int paperVal1 = 0;
int scissorsVal1 = 0;

int rockVal2 = 0;   // Variables to store the values from the buttons player 2
int paperVal2 = 0;
int scissorsVal2 = 0;


void setup() {
    
  pinMode(pin10, OUTPUT); //sets the LEDs as output pins
  pinMode(pin9, OUTPUT);
  pinMode(pin8, OUTPUT);

  pinMode(pin7, OUTPUT); //sets the LEDs as output pins
  pinMode(pin6, OUTPUT);
  pinMode(pin5, OUTPUT);

  pinMode(pin13, INPUT); //sets the buttons as input pins
  pinMode(pin12, INPUT);
  pinMode(pin11, INPUT);

  pinMode(pin4, INPUT); //sets the buttons as input pins
  pinMode(pin3, INPUT);
  pinMode(pin2, INPUT);
    
  //Serial.begin(9600);
  
  startGame();
  
}

void loop() {
  
  if (gameState == 0) {
    // good to go
    blinkCountDown(); //this is the countdown timer - make your choice
    checkButtons(); 
    checkResults(); // see who won the game
  } else {
    restartGame(); // starts the game all over
  }
  
 
}

void startGame() {
  gameState = 0;
}

void blinkCountDown() {//this is the countdown timer
    for (int i = 0; i<3; i++){
    ledState=!ledState;
    digitalWrite(pin8, ledState); // make the led change
    digitalWrite(pin7, ledState);
    delay(250);

    ledState=!ledState;
    digitalWrite(pin8, ledState); // make the led change
    digitalWrite(pin7, ledState);
    delay(250);
    }

    for (int i = 0; i<3; i++){
    ledState=!ledState;
    digitalWrite(pin9, ledState); // make the led change
    digitalWrite(pin6, ledState);
    delay(250);

    ledState=!ledState;
    digitalWrite(pin9, ledState); // make the led change
    digitalWrite(pin6, ledState);
    delay(250);
    }
    
    for (int i = 0; i<3; i++){
    ledState=!ledState;
    digitalWrite(pin10, ledState); // make the led change
    digitalWrite(pin5, ledState);
    delay(250);

    ledState=!ledState;
    digitalWrite(pin10, ledState); // make the led change
    digitalWrite(pin5, ledState);
    delay(250);
    }
}

void checkButtons() {
  //read the buttons
  while (counter<10) {
    rockVal1=digitalRead(pin4);
    paperVal1=digitalRead(pin3);
    scissorsVal1=digitalRead(pin2);
    rockVal2=digitalRead(pin11);
    paperVal2=digitalRead(pin12);
    scissorsVal2=digitalRead(pin13);
    delay(500);
    counter++; 
    }
  
//flash button release
    for (int i = 0; i<3; i++){
    ledState=!ledState;
    digitalWrite(pin10, ledState); // make the led change
    digitalWrite(pin5, ledState);
    delay(500);

    ledState=!ledState;
    digitalWrite(pin10, ledState); // make the led change
    digitalWrite(pin5, ledState);
    delay(500);
    }
    
    //display result
    digitalWrite(pin7, rockVal1); // make the led change
    digitalWrite(pin6, paperVal1);
    digitalWrite(pin5, scissorsVal1);
    digitalWrite(pin10, scissorsVal2); // make the led change
    digitalWrite(pin9, paperVal2);
    digitalWrite(pin8, rockVal2);
    delay(5000); 
} 
 

void checkResults() {//find the winner or a tie
  
   gameState = 1; 

  if (rockVal1==1 && rockVal2==1) {//rock tie
    for (int i = 0; i<5; i++){
    ledState=!ledState;
    digitalWrite(pin8, ledState); // make the led change
    digitalWrite(pin7, ledState);
    delay(250);

    ledState=!ledState;
    digitalWrite(pin8, ledState); // make the led change
    digitalWrite(pin7, ledState);
    delay(250);
    }
  } 

  else if (paperVal1==1 && paperVal2==1) {//paper tie
    for (int i = 0; i<5; i++){
    ledState=!ledState;
    digitalWrite(pin9, ledState); // make the led change
    digitalWrite(pin6, ledState);
    delay(250);

    ledState=!ledState;
    digitalWrite(pin9, ledState); // make the led change
    digitalWrite(pin6, ledState);
    delay(250);
    }
    }

  else if (scissorsVal1==1 && scissorsVal2==1) {//scissors tie
    for (int i = 0; i<5; i++){
    ledState=!ledState;
    digitalWrite(pin10, ledState); // make the led change
    digitalWrite(pin5, ledState);
    delay(250);

    ledState=!ledState;
    digitalWrite(pin10, ledState); // make the led change
    digitalWrite(pin5, ledState);
    delay(250);
    }
  } 

  else if (paperVal2==1 && rockVal1==1 || scissorsVal2==1 && paperVal1==1 || rockVal2==1 && scissorsVal1==1) {//player two wins
    for (int i = 0; i<5; i++){
    ledState=!ledState;
    digitalWrite(pin10, ledState); // make the led change
    digitalWrite(pin9, ledState);
    digitalWrite(pin8, ledState);
    delay(250);

    ledState=!ledState;
    digitalWrite(pin10, ledState); // make the led change
    digitalWrite(pin9, ledState);
    digitalWrite(pin8, ledState);
    delay(250);
    }
  }
  else if (paperVal1==1 && rockVal2==1 || scissorsVal1==1 && paperVal2==1 || rockVal1==1 && scissorsVal2==1) {//player one wins
   for (int i = 0; i<5; i++){
   ledState=!ledState;
    digitalWrite(pin7, ledState); // make the led change
    digitalWrite(pin6, ledState);
    digitalWrite(pin5, ledState);
    delay(250);

    ledState=!ledState;
    digitalWrite(pin7, ledState); // make the led change
    digitalWrite(pin6, ledState);
    digitalWrite(pin5, ledState);
    delay(250);
   }
  }
  
  else {
    for (int i = 0; i<5; i++){//no buttons pushed - this is an error
    ledState=!ledState;
    digitalWrite(pin7, ledState); // make the led change
    digitalWrite(pin6, ledState);
    digitalWrite(pin5, ledState);
    digitalWrite(pin10, ledState); // make the led change
    digitalWrite(pin9, ledState);
    digitalWrite(pin8, ledState);
    delay(250);

    ledState=!ledState;
    digitalWrite(pin7, ledState); // make the led change
    digitalWrite(pin6, ledState);
    digitalWrite(pin5, ledState);
    digitalWrite(pin10, ledState); // make the led change
    digitalWrite(pin9, ledState);
    digitalWrite(pin8, ledState);
    delay(250);
    }
  }

}

void restartGame() {
  gameState = 0;
  counter = 0;
    digitalWrite(pin7, LOW); //reset the LEDs
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin10,LOW); 
    digitalWrite(pin9, LOW);
    digitalWrite(pin8, LOW);
  delay(3000); 
}
