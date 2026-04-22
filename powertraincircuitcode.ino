bool breakPressed= false;
bool ignitionPressedOnce=false;
bool engineActive=false;
bool requiredCondition=false;
bool buzzerDone=false;

void setup() {
pinMode(13,INPUT); //Ignition Button Input
pinMode(12,INPUT); //Brake Throtle Input
pinMode(11,OUTPUT); //Motor Relay output
pinMode(10,OUTPUT); // TSAL output
pinMode(9,OUTPUT); //Buzzer Ouptput
pinMode(8,OUTPUT); //Brake Light Output
}

void loop() {

  if(digitalRead(12)==HIGH){ // Checks whether Brake Throttle is pressed or not
      breakPressed=true;
    digitalWrite(8,HIGH); // Commands the Brake light accordingly 
    }else if(digitalRead(12)==LOW){
       breakPressed=false;
      digitalWrite(8,LOW);
      }
  if(digitalRead(13)==HIGH && breakPressed){ // Checks wehther Ignition Button is On and Brake Pedal is pressed
    engineActive=true;
   
    if(!buzzerDone){ // Activates Buzzer
       buzzerDone=true;
       digitalWrite(9,HIGH);
       delay(2000);
       digitalWrite(9,LOW);
      }
  
     digitalWrite(11,HIGH); // Activates Motor relay
    }  
    if(engineActive){
      digitalWrite(10,HIGH); // Activates TSAL
 
      }
}
