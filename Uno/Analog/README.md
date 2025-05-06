# Arduino Uno Analog Projects

This directory contains projects that demonstrate the use of analog inputs and outputs on the Arduino Uno.

![Analog Circuit Diagram](image.png)

## Analog Pins on Arduino Uno
- 6 analog input pins (A0-A5)
- 6 analog output pins (PWM: 3, 5, 6, 9, 10, 11)
- 10-bit ADC resolution (0-1023)
- 8-bit PWM resolution (0-255)

## Common Analog Components
- Potentiometers
- Light Sensors (LDR)
- Temperature Sensors
- Analog Joysticks
- Pressure Sensors
- Sound Sensors

## Basic Analog Read Example
```cpp
int sensorValue = analogRead(A0);  // Read analog value from pin A0
```

## Basic Analog Write Example
```cpp
analogWrite(9, 128);  // Write PWM value (0-255) to pin 9
```

## Projects
- Coming soon...

## Notes
- Analog inputs use 10-bit resolution (0-1023)
- PWM outputs use 8-bit resolution (0-255)
- Use `map()` function to convert between ranges
- Consider using external ADC for higher resolution 