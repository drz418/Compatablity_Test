/*
  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 7,8,9 to ground

  based on the open source code @ http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// These constants are used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin1 = 9; // Analog output pin that the Yellow LED is attached to
const int analogOutPin2 = 8; // Analog output pin that the Green LED is attached to
const int analogOutPin3 = 7; // Analog output pin that the Blue LED is attached to


int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  
  if (sensorValue < 147) {
  
  //Setting the outpin and power and write the word to the serial monitor
  analogWrite(analogOutPin1, 150); // yellow light ON
  analogWrite(analogOutPin2, 255); // green light ON
  analogWrite(analogOutPin3, 255); // blue light ON
  
  Serial.print("\i"); }

 if (sensorValue > 147 && sensorValue < 293) {
  
  analogWrite(analogOutPin1, 0); // yellow light OFF
  analogWrite(analogOutPin2, 0); // green light OFF
  analogWrite(analogOutPin3, 255); // blue light ON
  
  Serial.print("\t love"); }

  if (sensorValue > 293 && sensorValue < 440) {
  
  analogWrite(analogOutPin1, 255); // yellow light ON
  analogWrite(analogOutPin2, 0); // green light OFF
  analogWrite(analogOutPin3, 0); // blue light OFF
  
  Serial.print("\t you"); }

  if (sensorValue > 440 && sensorValue < 586) {
  
  analogWrite(analogOutPin1, 0); // yellow light OFF
  analogWrite(analogOutPin2, 255); // green light ON
  analogWrite(analogOutPin3, 0); // blue light OFF
  
  Serial.print("\t lamp"); }
  
  if (sensorValue > 586 && sensorValue < 732) {
  
  analogWrite(analogOutPin1, 0); // yellow light OFF
  analogWrite(analogOutPin2, 255); // green light ON
  analogWrite(analogOutPin3, 255); // blue light ON
  
  Serial.print("\t tolerate"); }

  if (sensorValue > 732 && sensorValue < 878) {
  
  analogWrite(analogOutPin1, 255); // yellow light ON
  analogWrite(analogOutPin2, 255); // green light ON
  analogWrite(analogOutPin3, 0); // blue light OFF
  
  Serial.print("\t bagels"); }

if (sensorValue > 878) {
  analogWrite(analogOutPin2, 0); // green light OFF
  analogWrite(analogOutPin1, 255); // yellow light ON
  analogWrite(analogOutPin3, 255); // blue light ON
  Serial.print("\t see"); }
  
  // wait 2 milliseconds before the next loop for the analog-to-digital
  delay(2);
}
