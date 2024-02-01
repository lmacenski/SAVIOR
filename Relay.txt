const int relay1 = 13; const int relay2 = 12; const int relay3 = 11; const int relay4 = 10; 
const int relay5 = 9; const int relay6 = 8; const int relay7 = 7; const int relay8 = 6; 
const int max = 200; 
unsigned long H;
unsigned long V;
int speed = 0;
const int constant1 = 1493;
const int constant2 = 1500;
bool right = false;
bool left = false;
bool stop = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  // put your setup code here, to run once:
  pinMode(relay1, OUTPUT);// set pin as output for relay 1
  pinMode(relay2, OUTPUT);// set pin as output for relay 2
  pinMode(relay3, OUTPUT);// set pin as output for relay 1
  pinMode(relay4, OUTPUT);// set pin as output for relay 2
  pinMode(relay5, OUTPUT);// set pin as output for relay 1
  pinMode(relay6, OUTPUT);// set pin as output for relay 2
  pinMode(relay7, OUTPUT);// set pin as output for relay 1
  pinMode(relay8, OUTPUT);// set pin as output for relay 2

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  V = pulseIn(3, HIGH);
  H = pulseIn(2, HIGH);
  digitalWrite(relay1, LOW);// turn relay 2 OFF
  
   if(H<=1550 && H>=1450)
  {
    if(V<=1550 && V>=1450)
    {
      speed = 0;
      right = false;
      left = false;
    }
    else if(V>1550 && V<=1700)
    {
      speed = (V - 1497)/2;
      right = false;
      left = false;
    }
    else if(V>1700)
    {
      speed = max;
      right = false;
      left = false;
    }
    else if(V<1450&& V>=1300)
    {
      speed = (V - 1497)/2;
      right = false;
      left = false;
    }
    else if(V<1300)
    {
      speed = -max;
      right = false;
      left = false;
    }
  }
    else if(H>1550 && H<=1700)
    {
      speed = (H - 1497)/2;
      right = true;
      left = false;
    }
    else if(H>1700)
    {
      speed = max;
      right = true;
      left = false;
    }
    else if(H<1450&& H>=1300)
    {
      speed = (H - 1497)/2;
      right = false;
      left = true;
    }
    else if(H<1300)
    {
      speed = -max;
      right = false;
      left = true;
    }

    if(speed == 0)
    {
      digitalWrite(relay2, LOW);// turn relay 2 OFF
      digitalWrite(relay6, LOW);// turn relay 2 OFF
    }
    else if(left)
    {
      digitalWrite(relay2, HIGH);// turn relay 2 OFF
      digitalWrite(relay6, HIGH);// turn relay 2 OFF
      digitalWrite(relay3, HIGH);// turn relay 2 OFF
      digitalWrite(relay4, HIGH);// turn relay 2 OFF
      digitalWrite(relay7, LOW);// turn relay 2 OFF
      digitalWrite(relay8, LOW);// turn relay 2 OFF
    }
    else if(right)
    {
      digitalWrite(relay2, HIGH);// turn relay 2 OFF
      digitalWrite(relay6, HIGH);// turn relay 2 OFF
      digitalWrite(relay3, LOW);// turn relay 2 OFF
      digitalWrite(relay4, LOW);// turn relay 2 OFF
      digitalWrite(relay7, HIGH);// turn relay 2 OFF
      digitalWrite(relay8, HIGH);// turn relay 2 OFF
    }
    else if(speed > 0)
    {
      digitalWrite(relay2, HIGH);// turn relay 2 OFF
      digitalWrite(relay6, HIGH);// turn relay 2 OFF
      digitalWrite(relay3, HIGH);// turn relay 2 OFF
      digitalWrite(relay4, HIGH);// turn relay 2 OFF
      digitalWrite(relay7, HIGH);// turn relay 2 OFF
      digitalWrite(relay8, HIGH);// turn relay 2 OFF
    }
    else if(speed < 0)
    {
      digitalWrite(relay2, HIGH);// turn relay 2 OFF
      digitalWrite(relay6, HIGH);// turn relay 2 OFF
      digitalWrite(relay3, LOW);// turn relay 2 OFF
      digitalWrite(relay4, LOW);// turn relay 2 OFF
      digitalWrite(relay7, LOW);// turn relay 2 OFF
      digitalWrite(relay8, LOW);// turn relay 2 OFF
    }

}
