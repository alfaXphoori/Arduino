// C++ code
//
#define LED_RED 11
#define LED_R 3
#define LED_B 5
#define LED_G 6	
#define LED_LIGHT 8
#define LED_FR 7
#define LED_FO 9
#define LED_FY 2	
#define SOLAR_PIN A0
#define LIGHT_PIN A1
#define FORCE_PIN A2

float solar_val;
float solar_volt;
int bright_led;
int light_val;
int force_val;

float cal_solar_volt()
{
  solar_val = analogRead(SOLAR_PIN);
  solar_volt = (solar_val/1019)*5.0;
  return solar_volt;
}
void led_solar_status()
{
  solar_val = analogRead(SOLAR_PIN);
  bright_led = map(solar_val,0,1019,0,255);
  analogWrite(LED_RED, bright_led);
  //Serial.println(bright_led);
}
void set_color(int r, int g, int b)
{
  analogWrite(LED_R,r);
  analogWrite(LED_B,b);
  analogWrite(LED_G,g);
}
void rgb_solar_status()
{
  bright_led = map(solar_val,0,1019,0,4);
  //Serial.println(bright_led);
  if(bright_led ==4)
  {
	set_color(0,255,0);
  }
  else if(bright_led ==3)
  {
	set_color(255,255,0);
  }
  else if(bright_led ==2)
  {
    set_color(255,69,0);
  } 
  else if(bright_led <2)
  {
	set_color(255,0,0);
  }
}
void light_control()
{
  light_val = analogRead(LIGHT_PIN);
  if(light_val < 200)
  {
    digitalWrite(LED_LIGHT, HIGH);
    Serial.println("ON");
  }
  else
  {
    digitalWrite(LED_LIGHT, LOW);
  }
}
void force_status()
{
  force_val = analogRead(FORCE_PIN);
  Serial.println(force_val);
  if(force_val >300)
  {
    digitalWrite(LED_FR, 1);
    digitalWrite(LED_FO, 0);
    digitalWrite(LED_FY, 0);
  }
  else if(force_val >200)
  {
    digitalWrite(LED_FR, 0);
    digitalWrite(LED_FO, 1);
    digitalWrite(LED_FY, 0);
  }
  else if(force_val >100)
  {
    digitalWrite(LED_FR, 0);
    digitalWrite(LED_FO, 0);
    digitalWrite(LED_FY, 1);
  } 
}
void setup()
{
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_LIGHT, OUTPUT);
  pinMode(LED_FY, OUTPUT);
  pinMode(LED_FO, OUTPUT);
  pinMode(LED_FR, OUTPUT);
}

void loop()
{ 
  //Serial.println(cal_solar_volt());
  led_solar_status();
  rgb_solar_status();
  light_control();
  force_status();
  delay(100);
}

















