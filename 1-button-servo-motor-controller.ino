#include <Servo.h> // Include the Servo library to control the motor

#define thresholdInPin 15 // Define the input pin for the MyoWare sensor threshold value
#define myowareInPin 12 // Define the input pin for the MyoWare sensor value

Servo myservo; // Create a Servo object
static const int servoPin = 27; // Define the pin for the servo motor

int myowareValue = 0; // Variable to store the MyoWare sensor value

// Note about the treshold: the analog-to-digital converter (ADC) resolution varies between boards:
// - Arduino boards have a 10-bit ADC with a range of 0-1023
// - ESP boards (such as ESP32) have a 12-bit ADC with a range of 0-4095
// Depending on the board you are using, you may need to adjust the scaling factor in the code
// to account for these differences in ADC resolution.

int threshold = 700; // Initial threshold value to compare with the MyoWare sensor value


void setup() {
  pinMode(myowareInPin, INPUT); // Set the MyoWare sensor pin as an input
  pinMode(thresholdInPin, INPUT); // Set the threshold pin as an input
  pinMode(servoPin, OUTPUT); // Set the servo pin as an output
  myservo.attach(servoPin); // Attach the servo motor to the servo pin
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  myowareValue = analogRead(myowareInPin); // Read the MyoWare sensor value
  threshold = analogRead(thresholdInPin); // Read the threshold value
  Serial.println(myowareValue); // Print the MyoWare sensor value to the serial monitor
  Serial.println(threshold); // Print the threshold value to the serial monitor

  // If the MyoWare sensor value is greater than the threshold value
  if (myowareValue > threshold) {
    myservo.write(80); // Move the servo motor to the 80-degree position
    delay(200); // Wait for 200 milliseconds
    Serial.println("press"); // Print "press" to the serial monitor
  } else {
    myservo.write(130); // Move the servo motor to the 130-degree position
  }
  delay(100); // Wait for 100 milliseconds before the next loop iteration
}
