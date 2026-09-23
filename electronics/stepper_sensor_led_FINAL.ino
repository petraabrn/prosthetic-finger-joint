#include <Stepper.h>

const int stepsPerRevolution = 2048;  // Number of steps for a full 360-degree rotation 
const int ledPin = 5;                // Digital pin connected to the LED
const int trigPin = 6;             // Trig pin connected to the distance sensor
const int echoPin = 7;             // Trig pin connected to the distance sensor

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  // Initialize the stepper library for pins 8 through 11

void setup() {
  
  myStepper.setSpeed(10);   // Rotation speed of 100 rpm
  pinMode(ledPin, OUTPUT);  // LED is an output
  pinMode(trigPin, OUTPUT);  // Distance sensor is an output
  pinMode(echoPin, INPUT);  // Distance sensor is an input
  Serial.begin(115200);     // Initialize the serial port to see values on screen
  Serial.println("Starting");

}

void loop() {
  long duration;
  float cm;

  // Sense and fade
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = (duration * 0.034) / 2; 

  // LED brightness control
  int brightness = map(cm, 2, 20, 255, 0); 
  brightness = constrain(brightness, 0, 255); 
  analogWrite(ledPin, brightness); 

  // If your finger is close, move the motor just a tiny bit
  if (cm <= 10 && cm > 2) {
    myStepper.step(10); 
    Serial.print("Distance: "); Serial.println(cm);
    Serial.print("Brightness: "); 
  } 
  else if (cm > 25) {
    // If nothing is there, slowly move back to open
    myStepper.step(-10);
  }

  // Small delay so the sensor stays responsive
  delay(10); 
}