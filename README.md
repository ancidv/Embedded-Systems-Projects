Embedded Systems Projects

My learning journey in Embedded Systems using Embedded C, ESP32, sensors, and IoT.

Projects

1. LED Blinking using ESP32

- Objective: Blink an LED using ESP32.
- Concepts: GPIO, digital output, and delay.
- Tools: ESP32, Arduino IDE, LED.

2.Smart Food Freshness Detector

- Objective: To monitor food freshness using sensors and AI-based image classification.
- Hardware: ESP32, gas sensor, and DHT11 temperature and humidity sensor.
- Technologies: Embedded C, Python, Streamlit, and Teachable Machine.
Features:

- Monitors gas levels, temperature, and humidity.
- Uses AI image classification to distinguish fresh and spoiled food.
- Displays freshness information through a user interface.
- Learning outcomes: Sensor interfacing, ESP32 programming, IoT, and AI integration.
  
3.ESP32 based food freshness detector stimulation using a gas sensor and three led.

4.ESP32 Automatic Street Light

Project Description

An automatic street light simulation using ESP32 and an LDR sensor. The system detects surrounding light intensity and switches an LED ON in darkness and OFF in bright conditions.

Components

- ESP32 DevKit V1
- LDR sensor module
- LED
- 220Ω resistor

Connections

- LDR AO → GPIO 34
- LDR VCC → 3V3
- LDR GND → GND
- ESP32 GPIO 2 → 220Ω resistor → LED anode (+)
- LED cathode (−) → GND

Working

The ESP32 reads the LDR's analog value and compares it with a threshold. Based on the reading, it controls the LED automatically.

Tools and Technologies

- ESP32
- Wokwi circuit simulator
- C++ programming

Simulation

The circuit was designed and tested in Wokwi. The LDR light level can be adjusted to observe the LED switching and the sensor readings in the Serial Monitor.

Learning Outcomes

- Reading analog sensor values
- Using conditional statements
- Controlling an LED with ESP32 GPIO
- Understanding automatic lighting systems

More embedded systems projects will be added as I continue learning.

