// C++ code
//
#define LED_OUT_RED 8
#define LED_OUT_GREEN 9
#define SW_IN 2
#define BTN_IN 4
int val_sw = 0;
int val_btn = 0;
void led_out(int pin)
{
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_OUT_RED, OUTPUT);
  pinMode(LED_OUT_GREEN, OUTPUT);
  pinMode(SW_IN, INPUT);
  pinMode(BTN_IN, INPUT);
}

void loop()
{
  val_sw = digitalRead(SW_IN);
  digitalWrite(LED_OUT_RED, val_sw);
  val_btn = digitalRead(BTN_IN);
  digitalWrite(LED_OUT_GREEN, val_btn);
  Serial.print("SW : ");
  Serial.print(val_sw);
  Serial.print(", BTN : ");
  Serial.print(val_btn);
  Serial.println();
  delay(200);
  //led_out(LED_BUILTIN);
  //led_out(LED_OUT_RED);
  //led_out(LED_OUT_GREEN);
}

