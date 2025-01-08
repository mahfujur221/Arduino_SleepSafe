// Pin definitions
const int irSensorPin = 2;   // Pin for the IR sensor
const int relayPin = 8;       // Pin to control the relay (motor)
const int buzzerPin = 9;      // Pin to control the buzzer

// Timing variables
unsigned long closedTime = 0;
bool eyesClosed = false;
bool buzzerActivated = false;

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Start the motor initially
  // digitalWrite(relayPin, HIGH); // Assuming HIGH turns the motor ON
}

void loop() {
  int sensorValue = digitalRead(irSensorPin); // Read the IR sensor value

  // Check if the IR sensor detects an object (eyes closed)
  if (sensorValue == LOW) { // Assuming LOW means eyes are closed
    if (!eyesClosed) {
      eyesClosed = true;
      closedTime = millis(); // Record the time when eyes were first detected as closed
    } else {
      // If eyes are still closed, check the time
      if (millis() - closedTime >= 2000 && !buzzerActivated) {
        // Activate the buzzer after 2 seconds
        digitalWrite(buzzerPin, HIGH);
        buzzerActivated = true;
      }
      if (millis() - closedTime >= 4000) {
        // Stop the motor after another 2 seconds (4 seconds total)
        digitalWrite(relayPin, HIGH); // Assuming LOW turns the motor OFF
      }
    }
  } else {
    // Reset the state if eyes are open
    eyesClosed = false;
    buzzerActivated = false;
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    closedTime = 0; // Reset the timer
    digitalWrite(relayPin, LOW); // Ensure the motor is running
  }

  delay(100); // Small delay to avoid rapid looping
}