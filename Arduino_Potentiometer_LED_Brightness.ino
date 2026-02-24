/*
  ============================================
  Project Title : Arduino Potentiometer LED Brightness
  ============================================

  Description:
  This project controls LED brightness using a potentiometer.
  The analog value from the potentiometer is read by Arduino,
  then converted into a PWM signal to smoothly adjust
  the LED brightness level.

  Components:
  - Arduino Uno (or compatible board)
  - 10K Potentiometer
  - LED
  - 220 ohm Resistor
  - Breadboard
  - Jumper wires

  Wiring:
  Potentiometer:
    - Left pin   -> 5V
    - Right pin  -> GND
    - Middle pin -> A0

  LED:
    - Long leg (Anode)    -> Pin 9
    - Short leg (Cathode) -> 220 ohm resistor -> GND
*/

const int potPin = A0;     // Analog input pin for potentiometer
const int ledPin = 9;      // PWM output pin for LED

int potValue = 0;          // Stores analog value (0-1023)
int brightness = 0;        // Stores PWM value (0-255)

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read analog value from potentiometer
  potValue = analogRead(potPin);

  // Convert 0-1023 range to 0-255 for PWM
  brightness = map(potValue, 0, 1023, 0, 255);

  // Output PWM signal to control LED brightness
  analogWrite(ledPin, brightness);
}
