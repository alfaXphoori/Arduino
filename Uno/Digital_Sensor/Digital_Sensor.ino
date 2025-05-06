// C++ code
//
#define TILT_PIN 2
#define TEMPERATURE_PIN A0
#define TEMP_BLUE 3
#define TEMP_GREEN 4
#define TEMP_RED 5
#define SOIL_PIN A1
#define PIR_PIN 6
#define PIR_LED 7
#define SR04_TRIG 8
#define SR04_ECHO 9

int tiltVAL = 0;
float tempVAL = 0;
int soilVAL = 0;
int pirVAL = 0;
float sr04VAL = 0;

int tiltSensor()
{
  tiltVAL = digitalRead(TILT_PIN);
  return tiltVAL;
}

int tempSensor()
{
  int tempAnalog = analogRead(TEMPERATURE_PIN);
  tempVAL = map(tempAnalog, 20, 358 , -40, 125);
  // BLUE < 10 / GREEN 10-40 / RED >40
  if (tempVAL < 10)
  {
    digitalWrite(TEMP_BLUE, HIGH);
    digitalWrite(TEMP_GREEN, LOW);
    digitalWrite(TEMP_RED, LOW);
  }
  else if (tempVAL > 40)
  {
    digitalWrite(TEMP_BLUE, LOW);
    digitalWrite(TEMP_GREEN, LOW);
    digitalWrite(TEMP_RED, HIGH);
  }
  else 
  {
  	digitalWrite(TEMP_BLUE, LOW);
    digitalWrite(TEMP_GREEN, HIGH);
    digitalWrite(TEMP_RED, LOW);
  }
  return tempVAL;
}

int soilSensor()
{
  int soilAnalog = analogRead(SOIL_PIN); // A1
  soilVAL = map(soilAnalog, 0 , 876 , 0 ,100);
  return soilVAL;
}

int pirSensor()
{
  pirVAL = digitalRead(PIR_PIN);
  digitalWrite(PIR_LED, pirVAL);
  return pirVAL;
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TILT_PIN, INPUT);
  pinMode(TEMP_BLUE, OUTPUT);
  pinMode(TEMP_GREEN, OUTPUT);
  pinMode(TEMP_RED, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(PIR_LED, OUTPUT);
  pinMode(SR04_TRIG, OUTPUT);
  pinMode(SR04_ECHO, INPUT);
}

float sr04Sensor()
{
  long duration;
  digitalWrite(SR04_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(SR04_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(SR04_TRIG, LOW);
  
  duration = pulseIn(SR04_ECHO, HIGH);
  
  sr04VAL = duration * 0.035/2;
  return sr04VAL;
}

void loop()
{

  Serial.print(tiltSensor());
  Serial.print(" | ");
  Serial.print(tempSensor());
  Serial.print(" | ");
  Serial.print(soilSensor());
  Serial.print(" | ");
  Serial.print(pirSensor());
  Serial.print(" | ");
  Serial.print(sr04Sensor());
  Serial.println();
  delay(100);
}











