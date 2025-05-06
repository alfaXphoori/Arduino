# 🔌 Arduino Uno Analog Projects

This directory contains practical examples and projects demonstrating analog input/output capabilities of the Arduino Uno microcontroller.

![Analog Circuit Diagram](image.png)

## 📊 Scope
This repository focuses on:
- 📈 Analog input reading and processing
- ⚡ PWM (Pulse Width Modulation) output generation
- 🔍 Sensor interfacing and data acquisition
- 🚀 Real-world applications and projects
- 💡 Best practices for analog signal handling

## 🔧 Hardware Specifications

### 📥 Analog Input Pins (A0-A5)
- 📊 Resolution: 10-bit (0-1023)
- ⚡ Input Range: 0-5V
- ⏱️ Sampling Rate: ~10,000 samples/second
- 🔌 Input Impedance: 100MΩ

### 📤 PWM Output Pins (3,5,6,9,10,11)
- 📊 Resolution: 8-bit (0-255)
- ⏱️ Frequency: 
  - 490Hz (pins 5,6)
  - 980Hz (pins 3,9,10,11)
- 📈 Duty Cycle: 0-100%

## 🚀 Project: Voltage Level Indicator (Analog_RW.ino)

### 📋 Overview
This project demonstrates reading analog voltage levels and displaying them using multiple LEDs as a visual indicator. The system reads voltage from an analog input and lights up different combinations of LEDs based on the voltage level.

### 🛠️ Hardware Requirements
- 🔌 Arduino Uno
- 💡 4 LEDs (Green, Orange, Yellow, Red)
- ⚡ Analog voltage source (0-5V)
- 🔧 Resistors (220Ω for LEDs)

### 🔌 Pin Configuration
```cpp
#define ANL_IN     A0    // Analog input pin
#define LED_GREEN  8     // Green LED pin
#define LED_ORANGE 9     // Orange LED pin
#define LED_YELLOW 10    // Yellow LED pin
#define LED_RED    11    // Red LED pin
```

### 📊 Voltage Level Indicators
- > 4.00V: All LEDs ON
- > 3.00V: Orange, Yellow, Red LEDs ON
- > 2.00V: Yellow, Red LEDs ON
- > 1.00V: Red LED ON
- > 0.90V: All LEDs OFF

### 💻 Code Structure

#### 📈 Analog Value Reading
```cpp
float analog_value(int pin) {
  float analog_val = analogRead(pin);
  float analog_volt = (analog_val/1023)*5.0;
  return analog_volt;
}
```

#### 💡 LED Control Function
```cpp
void led_out(int G, int O, int Y, int R) {
  digitalWrite(LED_GREEN, G);
  digitalWrite(LED_ORANGE, O);
  digitalWrite(LED_YELLOW, Y);
  digitalWrite(LED_RED, R);
}
```

#### 📊 Voltage Level Detection
```cpp
void volt_step() {
  float analog_val_input = analog_value(ANL_IN);
  Serial.print(analog_val_input);
  
  if(analog_val_input > 4.00) {
    led_out(1,1,1,1);
  }
  else if(analog_val_input > 3.0) {
    led_out(0,1,1,1);
  }
  else if(analog_val_input > 2.0) {
    led_out(0,0,1,1);
  }
  else if(analog_val_input > 1.0) {
    led_out(0,0,0,1);
  }
  else if(analog_val_input > 0.9) {
    led_out(0,0,0,0);
  }
}
```

### ⚙️ Setup and Loop
```cpp
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
}

void loop() {
  volt_step();
  Serial.println();
  delay(100);
}
```

## 💡 Best Practices

### 🔌 Signal Conditioning
- 📊 Use voltage dividers for >5V signals
- 🔍 Implement RC filters for noise reduction
- ⚠️ Add protection circuits for sensitive inputs
- 📈 Consider signal amplification when needed

### 💻 Code Optimization
- ⏱️ Use appropriate sampling rates
- ⚠️ Implement proper error checking
- 🔧 Add sensor calibration routines
- 🔋 Optimize for power consumption

### 🔧 Hardware Considerations
- 🔌 Choose appropriate component values
- ⚡ Consider power supply requirements
- 🔌 Use proper grounding techniques
- 🛡️ Implement proper shielding when needed

## 📁 Project Structure
Each project in this directory includes:
- 📐 Circuit diagram
- 📋 Component list
- 💻 Code examples
- 🔧 Calibration instructions
- 🔍 Troubleshooting guide

## 🚀 Getting Started
1. 📐 Review the circuit diagram
2. 📋 Gather required components
3. 🔧 Build the circuit
4. 💻 Upload the code
5. 🔧 Calibrate if necessary
6. ✅ Test and debug

## 📝 Notes
- 📚 Always check component datasheets
- ⚡ Use appropriate voltage levels
- ⚠️ Implement proper error handling
- 🌡️ Consider environmental factors
- 📝 Document your modifications
- ✅ Test thoroughly before deployment
