![Project Image](https://res.cloudinary.com/dhmxvivgg/image/upload/v1785620176/etyra_seo/projects/project_4e90723d-166b-4dd3-a010-ebfa402939e5.jpg)

[English](README.md) | [Romanian](README-ro.md)

---

# Simple Bluetooth Music Player with Active Buzzer 🎵

## Overview 🚀
This project guides you through creating a cost-effective Bluetooth music player using an [Arduino Uno R3](https://electronicmarket.ro/product/arduino-uno-r3-smd-board-with-usb-cable), an [HC-05 Bluetooth Module [EN Market]](https://electronicmarket.ro/product/hc05-modul-bluetooth), and an [Active Piezo Buzzer (5V) [EN Market]](https://electronicmarket.ro/product/5v-buzzer-activ-12mm). The goal is to stream music wirelessly from a smartphone to an active buzzer, an ideal beginner project for those interested in wireless sound systems.

## Theory of Operation 💡
The active piezo buzzer operates by converting electrical signals into sound. When connected to the Arduino, it generates sound based on the frequency of the input signal. The HC-05 Bluetooth Module enables wireless communication between your smartphone and the Arduino, using the Serial Port Protocol (SPP) to transmit frequency data that modulates the buzzer.

## Hardware Setup 🔧

### Components and Pin Connections
| Component                                                                 | Arduino Uno R3 Pin |
|---------------------------------------------------------------------------|--------------------|
| [HC-05 Bluetooth Module [EN Market]](https://electronicmarket.ro/product/hc05-modul-bluetooth)  | RX to Pin 10, TX to Pin 11  |
| [Active Piezo Buzzer (5V) [EN Market]](https://electronicmarket.ro/product/5v-buzzer-activ-12mm) | Positive to Pin 9, Negative to GND |
| [400 Tie-Points Breadboard (Half Size) [EN Market]](https://electronicmarket.ro/product/400-puncte-fara-lipire-breadboard) | -                  |
| [Dupont Jumper Wires (Male-to-Male) [EN Market]](https://electronicmarket.ro/product/cabluri-jumper-de-20-cm-cu-40-de-pini-de-la-tata-la-tata) | -                  |

### Wiring Diagram Description
1. **Connect the HC-05 Module**: Use jumper wires to connect the RX pin of the HC-05 to pin 10 on the Arduino and the TX pin to pin 11.
2. **Connect the Active Buzzer**: Connect the positive pin to pin 9 on the Arduino and the negative pin to GND.
3. **Breadboard Setup**: Place the components onto the breadboard, ensuring a stable connection with the Arduino via jumper wires.

## Software Implementation 🛠️

### Arduino Sketch
```cpp
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
int buzzerPin = 9;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (BTSerial.available()) {
    char c = BTSerial.read();
    int frequency = (c - '0') * 100;
    tone(buzzerPin, frequency);
    Serial.print("Playing frequency: ");
    Serial.println(frequency);
  }
}
```

### Explanation
- **SoftwareSerial**: Used for communication between the Arduino and the HC-05 module.
- **tone()**: Generates sound on the buzzer at specified frequencies.

## Testing & Calibration 🔌
After uploading the sketch, pair your smartphone with the HC-05 module. Use a Bluetooth terminal app to send numeric values (e.g., '1', '2', '3') that correspond to different frequencies played by the buzzer.

**Example Serial Monitor Output:**
```
Playing frequency: 100
Playing frequency: 200
Playing frequency: 300
```

## Common Issues ⚠️

1. **No Sound from Buzzer**: Ensure buzzer connections are secure and the correct pins are used.
2. **Bluetooth Connection Fails**: Verify that the HC-05 is correctly paired with the smartphone.
3. **Unresponsive System**: Check if the Arduino is properly powered and connections are firm.

## Troubleshooting

- **Issue**: Buzzer produces a constant tone.
  - **Solution**: Check for continuous signals being sent from the Bluetooth app.

- **Issue**: Serial Monitor does not display frequency.
  - **Solution**: Confirm that the correct baud rate is set in the Serial Monitor.

- **Issue**: HC-05 not entering pairing mode.
  - **Solution**: Reset the HC-05 and ensure it is powered correctly.

## Next Steps and Improvement Ideas 💡

1. **Volume Control**: Incorporate a potentiometer to adjust the volume of the buzzer dynamically.
2. **Melody Playback**: Develop a more complex sketch that allows playing predefined melodies.
3. **Advanced Sound Modulation**: Use more sophisticated Bluetooth protocols to modulate sound properties such as tone and rhythm.

This simple Bluetooth music player project demonstrates the integration of basic electronic components to create a functional wireless sound system, with ample room for expansion and personalization.
