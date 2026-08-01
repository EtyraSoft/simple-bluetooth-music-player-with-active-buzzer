/*
  Project: Simple Bluetooth Music Player with Active Buzzer
  Description: This project uses an HC-05 Bluetooth Module to stream music from a smartphone to an Active Piezo Buzzer. 
               The Arduino Uno reads Bluetooth signals and plays corresponding tones on the buzzer.
  Components: Arduino Uno R3, HC-05 Bluetooth Module, Active Piezo Buzzer (5V), Breadboard, Jumper Wires
*/

#include <SoftwareSerial.h>  // Include software serial library to communicate with HC-05

// Pin Definitions
const int buzzerPin = 9;     // Pin connected to the Active Piezo Buzzer
const int rxPin = 10;        // RX pin of the HC-05 connected to Arduino pin 10
const int txPin = 11;        // TX pin of the HC-05 connected to Arduino pin 11

SoftwareSerial bluetooth(rxPin, txPin);  // Create a software serial port for the Bluetooth module

void setup() {
  // Initialize the serial communication for debugging
  Serial.begin(9600);
  Serial.println("Bluetooth Music Player Initialized");

  // Initialize the software serial communication for the Bluetooth module
  bluetooth.begin(9600);
  Serial.println("Bluetooth module ready for connection");

  // Set the buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Check if there's any data available from the Bluetooth module
  if (bluetooth.available()) {
    char receivedChar = bluetooth.read();  // Read the character sent from the smartphone
    Serial.print("Received: ");            // Print the received character for debugging
    Serial.println(receivedChar);

    // Play different tones based on the received character
    switch (receivedChar) {
      case '1':
        playTone(1000);  // Play a tone at 1000 Hz
        break;
      case '2':
        playTone(1500);  // Play a tone at 1500 Hz
        break;
      case '3':
        playTone(2000);  // Play a tone at 2000 Hz
        break;
      default:
        noTone(buzzerPin);  // Stop any tone if an unrecognized character is received
        break;
    }
  }
}

// Function to play a tone on the buzzer
void playTone(int frequency) {
  tone(buzzerPin, frequency, 500);  // Play tone with given frequency for 500 ms
  delay(500);                       // Wait for the tone to finish playing
  noTone(buzzerPin);                // Stop the tone
}