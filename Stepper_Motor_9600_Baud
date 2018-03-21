/*     Stepper Motor Control
 *      
 *  SRD
 *  
 */
// defines pins numbers
const int stePin1 = 4; 
const int dirPin1 = 5; 
const int stePin2 = 6; 
const int dirPin2 = 7; 

// declares variables as integers
int ByteReceived;
int loops = 0;
int state;
int number_of_rotations = 0;

//!! sets number of rotations
int end_rotations = 35;
//!! supposedly calculates forward movement. wire_gauge_calc == number_of_steps (stepper motor)
int wire_gauge_calc = 3;

//resets motor using wire_gauge_calc and number_of_rotations to be exact
void reset() {
  digitalWrite(dirPin2,HIGH);
  for(int x = 0; x < number_of_rotations + 1; x++){
    Serial.print("\n");
    Serial.print("Returned ");
    Serial.print(x);
    Serial.print(" mm");
    for(int i = 0; i < wire_gauge_calc; i++) {
      digitalWrite(stePin2,HIGH);
      delayMicroseconds(1300);
      digitalWrite(stePin2,LOW);
      delayMicroseconds(1300);
    }
  }
  number_of_rotations = 0;
  delay(10000);
}

// movement of motors
void movement(){
  // moves the spinner motor one full rotation 
  digitalWrite(dirPin1,LOW); 
  for(int x = 0; x < 200; x++) {
    digitalWrite(stePin1,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stePin1,LOW); 
    delayMicroseconds(1000); 
  }
  delay(250);
  
  // moves the mover motor forwards by a small degree once
  digitalWrite(dirPin2,LOW);
  for(int x = 0; x < wire_gauge_calc; x++) {
    digitalWrite(stePin2,HIGH);
    delayMicroseconds(1000);
    digitalWrite(stePin2,LOW);
    delayMicroseconds(1000);
  }
  // updates and prints out the number of rotations for every main loop
  number_of_rotations += 1;
  Serial.print("Number of rotations: ");
  Serial.print(number_of_rotations);
  Serial.print("\n");
  delay(500);
}
//initialises program
void setup() {
  // Sets up the four output pins
  delay(1000);
  pinMode(stePin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);  
  pinMode(stePin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  delay(1000);
  
  // sets the monitor/serial output channel
  Serial.begin(9600);

  delay(500);
  Serial.print("Wire gauge calcuation: ");
  Serial.print(wire_gauge_calc);
  Serial.print("\n");
}
//main body
void loop() {
  // pauses program until enter is hit to start winding.
  if (loops == 0) {
    loops = 1;
    Serial.print("\nEnter to start\n");
    while (Serial.available()==0){
      delay(1000);
    }
    Serial.parseInt();
  }
  // prevents excess turns being made (electrical issue)
  if (number_of_rotations < end_rotations){
    movement();
  }
  // activated if the end number of rotations is met. Resets motor or turns again.
  if (number_of_rotations >= end_rotations){
    Serial.println("Type 1 to turn once times or 0 to reset: ");
    // delays program until serial input recieved
    while (Serial.available()==0){
      delay(500);
    }
    // reads serial input and follows appropriate action
    if (Serial.available() > 0){
      ByteReceived = Serial.read();
      if (ByteReceived == '1'){
        movement();
        ByteReceived = 5;
      }
      if (ByteReceived == '0'){
        Serial.print("Resetting");
        reset();
        ByteReceived = 5;
        delay(3000);
        Serial.print("\n");
        Serial.print("Reset");
        Serial.print("\n");
        // while Serial.available() doesn't work here
        delay(1000000);
        while (Serial.available()==0){
          delay(1000);
        }
      }
    }
