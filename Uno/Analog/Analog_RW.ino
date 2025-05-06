#define ANL_IN 		A0
#define ANL_IN1 	A1
#define LED_GREEN 	8
#define LED_ORANGE 	9
#define LED_YELLOW 	10
#define LED_RED 	11

float analog_val = 0;
float analog_volt = 0;

float analog_value (int pin)
{
  analog_val = analogRead(pin);
  analog_volt =(analog_val/1023)*5.0;
  return analog_volt;
}
void led_out(int G, int O, int Y, int R)
{
  float analog_val_input = analog_value(ANL_IN);
  digitalWrite(LED_GREEN, G);
  digitalWrite(LED_ORANGE, O);
  digitalWrite(LED_YELLOW, Y);
  digitalWrite(LED_RED, R);
}
void volt_step()
{
  float analog_val_input = analog_value(ANL_IN);
  Serial.print(analog_val_input);
  if(analog_val_input>4.00)
  {
    led_out(1,1,1,1);
  }
  else if(analog_val_input>3.0)
  {
    led_out(0,1,1,1);
  }
  else if(analog_val_input>2.0)
  {
    led_out(0,0,1,1);
  }
  else if(analog_val_input>1.0)
  {
    led_out(0,0,0,1);
  }
  else if(analog_val_input > 0.9)
  {
    led_out(0,0,0,0);
  }
}
void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
}
void loop()
{
  volt_step();
  Serial.println();
  delay(100);
}
               
               
               
               
               