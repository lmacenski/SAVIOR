//Declare Reciever
const int vAxis = 3;
const int hAxis = 2;

//Declare Left Relays Pins
const int lRelay1 = 6;
const int lRelay2 = 7;
const int lStop = 8;

//Declare Right Relays Pins
const int rRelay1 = 11;
const int rRelay2 = 10;
const int rStop = 12;

//Declare e-Stop Pin
const int eStop = 1;

//Declare Readings
unsigned long H;
unsigned long V;

void eStop(){
  //Read Value of eStop Pin
  bool state = digitalRead(eStop);

  if(state == true){
    digitalWrite(rStop, LOW);
    digitalWrite(lStop, LOW);
    eStop();
  }
  else{
    return;
  }
}

void setup() {
  //Declare Inputs
  pinMode(vAxis, INPUT);
  pinMode(hAxis, INPUT);
  pinMode(eStop, INPUT);

  //Declare Left Relay Pins
  pinMode(lRelay1, OUTPUT);
  pinMode(lRelay2, OUTPUT);
  pinMode(lStop, OUTPUT);

  //Declare Right Relay Pins
  pinMode(rRelay1, OUTPUT);
  pinMode(rRelay2, OUTPUT);
  pinMode(rStop, OUTPUT);

  //Initialize Left Relays Low
  digitalWrite(lRelay1, LOW);
  digitalWrite(lRelay2, LOW);

  //Initialize Right Relays Low
  digitalWrite(rRelay1, LOW);
  digitalWrite(rRelay2, LOW);

  //Set e-Stops High
  digitalWrite(rStop, HIGH);
  digitalWrite(lStop, HIGH);

  //Initailize Serial
  Serial.begin(9600);
}

void left(bool state, bool direction){
  //Set Movement
  digitalWrite(lStop, state);
  //Set Polarity
  digitalWrite(lRelay1, direction);
  digitalWrite(lRelay2, direction);

}

void right(bool state, bool direction){
  //Set Movement
  digitalWrite(rStop, state);
  //Set Polarity
  digitalWrite(rRelay1, direction);
  digitalWrite(rRelay2, direction);
}

void turnLeft(){
  left(true, true);
  right(true, false);
}

void turnRight(){
  left(true, false);
  right(true, true);
}

void goForward(){
  left(true, true);
  right(true, true);
}

void goBackward(){
  left(true, false);
  right(true, false);
}

void stop(){
  right(false,false);
  left(false,false);

}

void loop() {
  //Setup eStop On Loop
  eStop();

  //Set V and H Values
  H = PulseIn(hAxis, HIGH);
  V = pulseIn(vAxis, HIGH);

  //Begin Code
  if(H<=1550 && H>=1450){
    if(V<=1550 && V>=1450)
    {
      stop();
    }
    else if(V>1550)
    {
      goForward();
    }
    else if(V<1450)
    {
      goBackward():
    }
  }
else if(H>1550)
    {
      turnRight();
    }
    else if(H<1450)
    {
      turnLeft();
    }

    
}
