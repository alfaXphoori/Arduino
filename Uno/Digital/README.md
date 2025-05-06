# 🚀 Arduino Uno Digital Projects

This directory contains practical examples and projects demonstrating digital input/output capabilities of the Arduino Uno microcontroller.

![Digital Circuit Diagram](image.png)

## 📋 Scope
This repository focuses on:
- 📥 Digital input reading and processing
- 📤 Digital output control
- 🔘 Switch and button interfacing
- 💡 LED control and patterns
- 🌟 Real-world applications and projects

## 🔧 Hardware Specifications

### 📌 Digital Pins
- 14 digital pins (0-13)
- Input/Output modes configurable
- Internal pull-up resistors available
- 5V logic level
- 40mA maximum current per pin

### 🔌 Built-in Components
- LED_BUILTIN (Pin 13)
- Reset button
- Power LED
- TX/RX LEDs

## 🎮 Project: Digital Input/Output Control (Digital.ino)

### 📝 Overview
This project demonstrates reading digital inputs from switches and buttons, and controlling LED outputs based on their states. The system reads the state of a switch and a button, then controls two LEDs accordingly.

### 📦 Hardware Requirements
- Arduino Uno
- 2 LEDs (Red and Green)
- 1 Switch
- 1 Push Button
- Resistors (220Ω for LEDs)
- 10kΩ pull-up resistors for inputs

### 🔌 Pin Configuration
```cpp
#define LED_OUT_RED    8    // Red LED output pin
#define LED_OUT_GREEN  9    // Green LED output pin
#define SW_IN          2    // Switch input pin
#define BTN_IN         4    // Button input pin
```

### ⚡ Functionality
- 🔴 Switch controls Red LED
- 🟢 Button controls Green LED
- 📊 Serial monitor displays input states
- 💫 Optional LED blinking function available

### 💻 Code Structure

#### 💡 LED Control Function
```cpp
void led_out(int pin) {
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);
}
```

#### ⚙️ Setup Configuration
```cpp
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_OUT_RED, OUTPUT);
  pinMode(LED_OUT_GREEN, OUTPUT);
  pinMode(SW_IN, INPUT);
  pinMode(BTN_IN, INPUT);
}
```

#### 🔄 Main Loop
```cpp
void loop() {
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
}
```

## ⭐ Best Practices

### 📥 Input Handling
- Use pull-up resistors for switches
- Implement debouncing for buttons
- Check input states regularly
- Handle input errors gracefully

### 📤 Output Control
- Use appropriate current-limiting resistors
- Consider power consumption
- Implement proper timing
- Use appropriate pin modes

### ⚡ Code Optimization
- Use appropriate delays
- Implement proper error checking
- Optimize for power consumption
- Use appropriate pin assignments

## 📁 Project Structure
Each project in this directory includes:
- 📐 Circuit diagram
- 📋 Component list
- 💻 Code examples
- ⚙️ Calibration instructions
- 🔧 Troubleshooting guide

## 🚀 Getting Started
1. 📐 Review the circuit diagram
2. 📦 Gather required components
3. 🔌 Build the circuit
4. 💻 Upload the code
5. 🔍 Test and debug

## 📝 Notes
- 📚 Always check component datasheets
- ⚡ Use appropriate voltage levels
- ⚠️ Implement proper error handling
- 🌍 Consider environmental factors
- 📝 Document your modifications
- ✅ Test thoroughly before deployment