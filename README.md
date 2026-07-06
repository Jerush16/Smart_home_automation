ESP32 Smart Home Automation

IoT-based home automation system built on ESP32, with dynamic Wi-Fi provisioning, cloud-based remote control, and closed-loop climate control — no hardcoded credentials, no manual re-flashing when the network changes.

<!-- Add a hero image or demo GIF here: ![demo](assets/demo.gif) -->
Why this project (not just "another Blynk tutorial")

Most beginner ESP32 IoT projects hardcode SSID/password and rebuild firmware for every deployment. This project uses WiFiManager to eliminate that: on first boot (or after a Wi-Fi failure), the ESP32 spins up its own access point, serves a configuration portal, and lets the user provision credentials without re-flashing. That's the difference between a demo and a deployable device.

The temperature-triggered AC control isn't a simple if statement in isolation — it's implemented as a debounced threshold controller to avoid relay chatter when readings hover near 35°C.

Features

FeatureImplementationDynamic Wi-Fi provisioningWiFiManager library, captive portal fallbackCloud dashboard & controlBlynk (virtual pins for LED, temp/humidity display, motion alerts)Motion detectionPIR sensor → Blynk push notificationTemperature & humidity monitoringDHT11, polled every N secondsRemote LED controlBlynk app toggle → GPIO relay/LEDAutomatic AC controlRelay triggered when temp > 35°C, with debounce to prevent relay chatter

Hardware


ESP32 Dev Board
DHT11 temperature & humidity sensor
PIR motion sensor
Relay module (AC control)
LED (manual control demo)
Breadboard, jumper wires, 5V supply


<!-- Add wiring diagram: ![circuit](assets/circuit_diagram.png) -->
Pin Connections

ComponentESP32 PinDHT11 DataGPIO ??PIR OUTGPIO ??LEDGPIO ??Relay INGPIO ??

(fill in your actual pin mapping)

Software Setup


Install Arduino IDE + ESP32 board support.
Install libraries: WiFiManager, Blynk, DHT sensor library.
Flash smart_home_automation.ino to the ESP32.
On first boot, connect to the ESP32's setup AP (SSID shown on serial monitor) and enter your home Wi-Fi + Blynk auth token via the config portal.
Open the Blynk app and bind widgets to the virtual pins listed in the code.


Project Structure

smart-home-automation/
├── smart_home_automation.ino
├── README.md
├── assets/
│   ├── circuit_diagram.png
│   └── demo.gif
└── docs/
    └── blynk_widget_mapping.md

Demo

<!-- Embed a short video/gif of PIR trigger → notification, temp crossing 35°C → relay firing, LED toggle from app -->
Future Improvements


Replace DHT11 with DHT22/BME280 for better accuracy
Add OTA firmware updates
Add hysteresis band instead of single threshold for AC control (e.g., ON at 35°C, OFF at 33°C) to further reduce relay wear
