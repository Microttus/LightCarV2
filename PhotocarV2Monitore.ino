//Martin Økter
//12.03.2022
//Photocar

#include "Carcontrol.hh"
#include "pid.hh"

int photoRPin = A1;
int photoLPin = A0;
int photoMPin = A2;
int motorLPin = 6;
int motorRPin = 5;
int interruptPin1 = 2;
int interruptPin2 = 3;

volatile int rightWheelCount = 0; 
volatile int leftWheelCount = 0;

CarControl PhotoCar;
PID LeftWheelCtrl(200, 100, 10);
PID RightWheelCtrl(200, 100, 10);


void setup() {
  //Setup of the pin modes, and other code which is only to be run ones

  Serial.begin(9600);
  
  pinMode(photoRPin, INPUT);
  pinMode(photoLPin, INPUT);
  pinMode(photoMPin, INPUT);
  pinMode(motorRPin, OUTPUT);
  pinMode(motorLPin, OUTPUT);

  // Interrupt Setup
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), trigRightWheel, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), trigLeftWheel, RISING);

}


void loop() {
  //Main loop for your code which is supposed to be run for as long as the Arduino have power
  
  int lightR = analogRead(photoRPin); //Read value of photoresistor 1
  int lightL = analogRead(photoLPin); //Read value of photoresistor 2
  int lightM = analogRead(photoMPin); //Read value of photoresistor 3

  PhotoCar.UpdateSumAndDiff(lightR, lightL, lightM);

  PhotoCar.CalculateSpeed();

  PhotoCar.UpdateWheelSpeed(rightWheelCount, leftWheelCount);

  int motorPWMRight = int(RightWheelCtrl.calcsaturation(PhotoCar.getWheelSpeedRight(), PhotoCar.getWheelReqRight(), 0, 254));
  int motorPWMLeft = int(LeftWheelCtrl.calcsaturation(PhotoCar.getWheelSpeedLeft(), PhotoCar.getWheelReqLeft(), 0, 200));

  int pwmMin = 30;

  analogWrite(motorRPin, motorPWMRight + pwmMin);  //Write to motorcontroller
  analogWrite(motorLPin, motorPWMLeft + pwmMin);  //-||-

  delay(10); //Constrict the motor for running to fast

  // Printing data
  Serial.print("Values from light sensor R: ");
  Serial.print(lightR);
  Serial.print(" L: ");
  Serial.print(lightL);
  Serial.print(" M: ");
  Serial.print(lightM);
  //Serial.print(" - Motor base speed: ");
  //Serial.print(motorBaseSpeed);
  //Serial.print(" - Corection factor: ");
  //Serial.print(corrSpeed);
  Serial.print(" - Wheel speed R: ");
  Serial.print(PhotoCar.getWheelSpeedRight());
  Serial.print(" L: ");
  Serial.print(PhotoCar.getWheelSpeedLeft());
  Serial.print(" - Request speed R: ");
  Serial.print(PhotoCar.getWheelReqRight());
  Serial.print(" L: ");
  Serial.print(PhotoCar.getWheelReqLeft());
  Serial.print(" - PWM signal R: ");
  Serial.print(motorPWMRight);
  Serial.print(" L: ");
  Serial.print(motorPWMLeft);
  Serial.print(" Right Count: ");
  Serial.print(rightWheelCount);
  Serial.print(" Left Count: ");
  Serial.println(leftWheelCount);
}

void trigRightWheel() {
  rightWheelCount += 1;
}

void trigLeftWheel() {
  leftWheelCount += 1;
}

void forSerialPrint() {
  
}
