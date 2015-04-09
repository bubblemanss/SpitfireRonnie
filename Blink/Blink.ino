#include <Servo.h>
  Servo servo;
  Servo servo2;
  int servoPin = 9;
  int servo2Pin = 10;
  int rightA = 4;
  int rightB = 7;
  int leftA = 2;
  int leftB = 8;
  char input;
void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo2.attach(servo2Pin);
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  //A backwards
  //B forwards
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available()){
    input = Serial.read();
  }
  if (input == 'w'){
    stopMotor();
    moveForward(255);
  }
  else if (input =='a'){
    stopMotor();
    turnLeft();
  }
  else if (input =='s'){
    stopMotor();
    moveBackward(255);
  }
  else if (input =='d'){
    stopMotor();
    turnRight();
  }
  else if (input == 'j'){
    openClaw();
  }
  else if (input =='k'){
    closeClaw();
  }
  else if (input =='l'){
    tightClose();
  }
  else{
    stopMotor();
  }
}

void openClaw(){
  servo.write(0);
  servo2.write(180);
}

void closeClaw(){
  servo.write(90);
  servo2.write(90);
}

void tightClose(){
  servo.write(55);
  servo2.write(115);
}

void moveForward(int val){
  digitalWrite(rightB, val);
  digitalWrite(leftB, val);
}

void moveBackward(int val){
  digitalWrite(rightA, val);
  digitalWrite(leftA, val);
}

void stopMotor(){
  digitalWrite(rightA, 0);
  digitalWrite(rightB, 0);
  digitalWrite(leftA, 0);
  digitalWrite(leftB, 0);
}

void turnLeft(){
  digitalWrite(rightB, 255);
  digitalWrite(leftA, 0);
  digitalWrite(leftB, 0);
}

void turnRight(){
  digitalWrite(leftB, 255);
  digitalWrite(rightA, 0);
  digitalWrite(rightB, 0);
}
