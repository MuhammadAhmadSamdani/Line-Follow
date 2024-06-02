//right motor
int Rightpwm=2;
int Rihtforward=3;
int Rightbackword=4;

//left motor
int Leftpwm=5;
int Leftforward=7;
int Leftbackword=6;

//sensors 
// Mostr Right sensor
int smrv=36;
// Right sensor
int srv=38;
// center sensro
int scv=40;
// left sensor
int slv=42;
// most left sensor
int smlv=44;

//speeds control
int speed=120;
int turn=120;
int slow=120;
int stop=0;

//sensor logic
int black=0;
int white=1;

int pass = 0;

//logic flags

int count=0;

int smr, sr, sc, sl, sml ;



void setup(){

 Serial.begin(9600);

  // Define Pinmode For motor  
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);

  // Define PinMode for Sensor 
    pinMode(36,INPUT);
    pinMode(38,INPUT);
    pinMode(40,INPUT);
    pinMode(42,INPUT);
    pinMode(44,INPUT);
}

void loop(){

  smr=digitalRead(smrv);
  sr=digitalRead(srv);
  sc=digitalRead(scv);
  sl=digitalRead(slv);
  sml=digitalRead(smlv);

  // Print sensor values
    Serial.print("Sensor Right: ");
    Serial.print(sr);
    Serial.print(" ");
    Serial.print("Sensor Center: ");
    Serial.print(sc);
    Serial.print("");
    Serial.print("Sensor Left ");
    Serial.print(sl);
    Serial.println();
  // function
    linefollow();
}

// this function is used for line follow
void linefollow(){
  // define sensor 
    smr=digitalRead(smrv);
    sr=digitalRead(srv);
    sc=digitalRead(scv);
    sl=digitalRead(slv);
    sml=digitalRead(smlv);

  // logic for motor rotation 
  if(sr==white && sc==black && sl==white)
  {
    forward();
  }
  else if(sr==black && sc==black && sl==white)
  {
    right();
  }
  else if(sr==white && sc==black && sl==black)
  {
    left();
  }

}

void forward(){
  digitalWrite(Rforward,HIGH);
  digitalWrite(Rbackword,LOW);
  digitalWrite(Lforward,HIGH);
  digitalWrite(Lbackword,LOW);
  analogWrite(Lpwm,speed);
  analogWrite(Rpwm,speed);
}

// For backward direction
void backword(){
  digitalWrite(Rforward,LOW);
  digitalWrite(Rbackword,HIGH);
  digitalWrite(Lforward,LOW);
  digitalWrite(Lbackword,HIGH);
  analogWrite(Lpwm,speed);
  analogWrite(Rpwm,speed);

}

// For stop motor
void halt(){
    digitalWrite(Rforward,LOW);
    digitalWrite(Rbackword,LOW);
    digitalWrite(Lforward,LOW);
    digitalWrite(Lbackword,LOW);
    analogWrite(Lpwm,0);
    analogWrite(Rpwm,0);
}

// For Left Turn
void left(){
  //Define motor direction pin
    digitalWrite(Rforward,HIGH);
    digitalWrite(Rbackword,LOW);
    digitalWrite(Lforward,LOW);
    digitalWrite(Lbackword,LOW);
  // Define motor speed
    analogWrite(Lpwm,speed);
    analogWrite(Rpwm,speed);
}

// For  Right Turn
void right(){
  // Define motor direction pin
    digitalWrite(Rforward,LOW);
    digitalWrite(Rbackword,LOW);
    digitalWrite(Lforward,HIGH);
    digitalWrite(Lbackword,LOW);
  // Define motor speed
    analogWrite(Lpwm,speed);
    analogWrite(Rpwm,speed);
}

