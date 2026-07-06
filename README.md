# ESP32 Smart Home Automation System

## Overview
This project is an IoT-based Smart Home Automation System developed using ESP32. It integrates Blynk IoT Cloud to monitor environmental conditions and remotely control home appliances. Wi-Fi Manager is used to simplify network configuration, allowing the device to connect to different Wi-Fi networks without modifying the source code.

## Features

✔ Motion detection using PIR sensor

✔ Visual indication using LED when motion is detected

✔ Remote LED control through the Blynk mobile application

✔ Temperature and humidity monitoring using DHT11

✔ Live sensor data displayed on the Blynk dashboard

✔ Automatic AC control when temperature exceeds 35°C

✔ Wi-Fi Manager support for dynamic Wi-Fi configuration

## Hardware Used

- ESP32
- PIR Motion Sensor
- DHT11 Temperature and Humidity Sensor
- LEDs
- Resistors
- Breadboard
- Jumper Wires

## Software Used

- Arduino IDE
- ESP32 Board Package
- Blynk IoT Platform
- WiFiManager Library
- DHT Library

## Working

1. ESP32 connects to Wi-Fi using WiFiManager.
2. Sensor data is sent to the Blynk dashboard.
3. PIR sensor detects motion and turns ON an indicator LED.
4. Users can remotely control an LED from the Blynk app.
5. If the temperature exceeds 35°C, the AC output turns ON automatically.
6. Live temperature and humidity values are continuously updated in Blynk.

## Future Improvements

- Voice assistant integration
- Energy monitoring
- Fire and gas detection
- Smart scheduling
- OTA firmware updates

