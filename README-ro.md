![Project Image](https://res.cloudinary.com/dhmxvivgg/image/upload/v1785620176/etyra_seo/projects/project_4e90723d-166b-4dd3-a010-ebfa402939e5.jpg)

[English](README.md) | [Romanian](README-ro.md)

---

# Player de Muzică Bluetooth Simplu cu Buzzer Activ 🎵

## Prezentare Generală 🚀
Acest proiect te ghidează prin crearea unui player de muzică Bluetooth rentabil folosind un [Arduino Uno R3](https://electronicmarket.ro/product/arduino-uno-r3-smd-board-cu-cablu-usb), un [HC-05 Bluetooth Module [RO Market]](https://electronicmarket.ro/product/hc05-modul-bluetooth) și un [Active Piezo Buzzer (5V) [RO Market]](https://electronicmarket.ro/product/5v-buzzer-activ-12mm). Scopul este să redai muzică fără fir de pe un smartphone către un buzzer activ, un proiect ideal pentru începătorii interesați de sisteme de sunet wireless.

## Teoria Funcționării 💡
Buzzerul piezo activ funcționează prin convertirea semnalelor electrice în sunet. Când este conectat la Arduino, acesta generează sunet pe baza frecvenței semnalului de intrare. Modulul Bluetooth HC-05 permite comunicarea fără fir între smartphone și Arduino, folosind Protocolul de Port Serial (SPP) pentru a transmite date de frecvență care modulează buzzerul.

## Configurarea Hardware 🔧

### Componente și Conexiuni Pin
| Componentă                                                                 | Pin Arduino Uno R3 |
|---------------------------------------------------------------------------|--------------------|
| [HC-05 Bluetooth Module [RO Market]](https://electronicmarket.ro/product/hc05-modul-bluetooth)  | RX la Pin 10, TX la Pin 11  |
| [Active Piezo Buzzer (5V) [RO Market]](https://electronicmarket.ro/product/5v-buzzer-activ-12mm) | Pozitiv la Pin 9, Negativ la GND |
| [400 Tie-Points Breadboard (Half Size) [RO Market]](https://electronicmarket.ro/product/400-puncte-fara-lipire-breadboard) | -                  |
| [Dupont Jumper Wires (Male-to-Male) [RO Market]](https://electronicmarket.ro/product/cabluri-jumper-de-20-cm-cu-40-de-pini-de-la-tata-la-tata) | -                  |

### Descrierea Diagramei de Cablare
1. **Conectează Modulul HC-05**: Folosește cabluri jumper pentru a conecta pinul RX al HC-05 la pinul 10 pe Arduino și pinul TX la pinul 11.
2. **Conectează Buzzerul Activ**: Conectează pinul pozitiv la pinul 9 pe Arduino și pinul negativ la GND.
3. **Configurarea Breadboard-ului**: Plasează componentele pe breadboard, asigurând o conexiune stabilă cu Arduino prin cabluri jumper.

## Implementarea Software 🛠️

### Sketch Arduino
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

### Explicație
- **SoftwareSerial**: Folosit pentru comunicarea între Arduino și modulul HC-05.
- **tone()**: Generează sunet pe buzzer la frecvențe specificate.

## Testare și Calibrare 🔌
După încărcarea sketch-ului, împerechează smartphone-ul cu modulul HC-05. Folosește o aplicație terminal Bluetooth pentru a trimite valori numerice (de ex., '1', '2', '3') care corespund diferitelor frecvențe redate de buzzer.

**Exemplu de Ieșire Monitor Serial:**
```
Playing frequency: 100
Playing frequency: 200
Playing frequency: 300
```

## Probleme Comune ⚠️

1. **Niciun Sunet de la Buzzer**: Asigură-te că conexiunile buzzerului sunt sigure și că sunt folosiți pinii corecți.
2. **Conexiunea Bluetooth Eșuează**: Verifică dacă HC-05 este corect împerecheat cu smartphone-ul.
3. **Sistem Neresponsiv**: Verifică dacă Arduino este alimentat corespunzător și conexiunile sunt ferme.

## Depanare

- **Problemă**: Buzzerul produce un ton constant.
  - **Soluție**: Verifică dacă sunt trimise semnale continue din aplicația Bluetooth.

- **Problemă**: Monitorul Serial nu afișează frecvența.
  - **Soluție**: Confirmă că rata de baud corectă este setată în Monitorul Serial.

- **Problemă**: HC-05 nu intră în modul de împerechere.
  - **Soluție**: Resetează HC-05 și asigură-te că este alimentat corect.

## Pași Următori și Idei de Îmbunătățire 💡

1. **Controlul Volumului**: Încorporează un potențiometru pentru a ajusta volumul buzzerului dinamic.
2. **Redare Melodii**: Dezvoltă un sketch mai complex care permite redarea melodiilor predefinite.
3. **Modulare Avansată a Sunetului**: Folosește protocoale Bluetooth mai sofisticate pentru a modula proprietăți ale sunetului precum tonul și ritmul.

Acest proiect simplu de player de muzică Bluetooth demonstrează integrarea componentelor electronice de bază pentru a crea un sistem de sunet wireless funcțional, cu suficient spațiu pentru extindere și personalizare.
