#include <Servo.h>

#define DCMOTOR_IN_1 4
#define DCMOTOR_IN_2 11
#define DCMOTOR_IN_3 10
#define DCMOTOR_OUT 5
#define GEAR_IN A0
#define GEAR_OUT 6
#define SERVO_OUT 9
#define SERVO_L 8
#define SERVO_R 7
#define ENCODER_A 2
#define ENCODER_B 3

Servo myServo;

volatile long encoderPos = 0; 

void dcMotor()
{
  int dcVal_1 = digitalRead(DCMOTOR_IN_1);
  int dcVal_2 = digitalRead(DCMOTOR_IN_2);
  int dcVal_3 = digitalRead(DCMOTOR_IN_3);
  
  if (dcVal_1 == 1)
  {
    analogWrite(DCMOTOR_OUT, 64);
  }
  if (dcVal_2 == 1)analogWrite(DCMOTOR_OUT, 128);
  if (dcVal_3 == 1)analogWrite(DCMOTOR_OUT, 255);
}

void gearMotor()
{
  int gearAnalog = analogRead(GEAR_IN);
  int gearSpeed = map(gearAnalog,0 ,1023 ,0 ,255);
  analogWrite(GEAR_OUT, gearSpeed);
}

void servoMoter()
{
  int servoValL = digitalRead(SERVO_L);
  int servoValR = digitalRead(SERVO_R);
  
  if (servoValL == 1)myServo.write(180);
  else if (servoValR == 1)myServo.write(0);
  else myServo.write(90);
}

void setup()
{
  Serial.begin(9600);
  pinMode(DCMOTOR_IN_1, INPUT);
  pinMode(DCMOTOR_IN_2, INPUT);
  pinMode(DCMOTOR_IN_3, INPUT);
  pinMode(DCMOTOR_OUT, OUTPUT);
  pinMode(GEAR_OUT, OUTPUT);
  pinMode(SERVO_L, INPUT);
  pinMode(SERVO_R, INPUT);
  myServo.attach(SERVO_OUT);
  pinMode(ENCODER_A, INPUT);
  pinMode(ENCODER_B, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), updateEncoder, CHANGE);
}
                  
void updateEncoder() {
  
  int MSB = digitalRead(ENCODER_A); 
  int LSB = digitalRead(ENCODER_B); 
   
  if (MSB == LSB)
  {
    encoderPos++;
  }
  else encoderPos--;
  
}
                  
void loop()
{ 
  Serial.println(encoderPos);
  servoMoter();
  dcMotor();
  gearMotor();
  delay(100); // Wait for 1000 millisecond(s)
}













