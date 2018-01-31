int button; //Keyboard for now
int currentFloor=1; //Floor where the lift is
int Floor; //Floor where the lift goes
int pinMotor = 13; //The motor symbolize the lift's action
//LEDS shows on which floor the lift is
int led3 = 12;
int led2 = 11;
int led1 = 10;

void setup() {
//Initialization
  Serial.begin(9600);
//Definition of digital outputs
  pinMode(pinMotor, OUTPUT); //Motor 
  pinMode(led3, OUTPUT); //LED3
  pinMode(led2, OUTPUT); //LED2
  pinMode(led1, OUTPUT); //LED1
//Initialization of digital outputs status
  digitalWrite(pinMotor, LOW); 
  digitalWrite(led3, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led1, HIGH); //At the beginning, the lift is on the first floor
}

void loop() {
  //We want to drive the motor according to the floor on which the lift was called
  //We need to read the key which was pressed
  //The action of the motor depends on the current floor and the destination floor
  if(Serial.available()>0){ //If we can read the keyboard
    button = Serial.read(); //Save the key to compare it
    if(button=='1'){//The lift must go on the first floor
      Floor = 1; 
      setLedsOff(); //Lift is moving
      setAscend(Floor,currentFloor); //Drive the motor
      currentFloor = Floor; //Actualize the currentfloor
      Serial.println(currentFloor); //Advise user
      digitalWrite(led1, HIGH); //Switch on the LED
    }else if (button=='2'){//The lift must go on the second floor
      Floor = 2;
      setLedsOff();
      setAscend(Floor,currentFloor);
      currentFloor = Floor;
      Serial.println(currentFloor);
      digitalWrite(led2, HIGH);
    }else if (button=='3'){//The lift must go on the third floor
      Floor = 3;
      setLedsOff();
      setAscend(Floor,currentFloor);
      currentFloor = Floor;
      Serial.println(currentFloor);
      digitalWrite(led3, HIGH);
    }
  }
}

//Function to drive the motor according to the lift's action
void setAscend(int Floor, int currentFloor){
   /*The delay during the motor rotate correspond to the level difference
    * between the current floor and the destination floor.
    * We admit the lift take 3 seconds to climb one level
    */
   int wait = abs(currentFloor-Floor); 
   wait*=3;//conversion of waiting time in seconds
   Serial.print("Lifts is coming in : "); //Advertise user
   Serial.print(wait);
   Serial.println(" seconds");
   wait*=1000; //conversion in ms to be used by the function
   digitalWrite(pinMotor, HIGH); //Motor on
   delay(wait);
   digitalWrite(pinMotor, LOW); //Motor off 
   Serial.print("Current Floor : "); //Advertise user
}

//Switch off the LEDs when the lift is moving
void setLedsOff(){
   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);
   digitalWrite(led3, LOW);
}


