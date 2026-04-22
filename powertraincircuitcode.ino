// -----------------------------
// SAE E-BAJA Start-Up Logic
// Arduino UNO Control Code
// -----------------------------

// State Variables
bool brakePressed = false;     // Tracks brake pedal status
bool engineActive = false;     // Tracks if system is in Ready-to-Drive Mode
bool buzzerDone = false;       // Ensures buzzer runs only once

void setup() {
  // -------- INPUTS --------
  pinMode(13, INPUT); // Ignition Button
  pinMode(12, INPUT); // Brake Pedal Input

  // -------- OUTPUTS --------
  pinMode(11, OUTPUT); // Motor Relay (AIR control)
  pinMode(10, OUTPUT); // TSAL Indicator
  pinMode(9, OUTPUT);  // RTDS Buzzer
  pinMode(8, OUTPUT);  // Brake Light
}

void loop() {

  // -----------------------------
  // BRAKE LOGIC
  // -----------------------------
  // Check if brake pedal is pressed
  if (digitalRead(12) == HIGH) {
    brakePressed = true;
    digitalWrite(8, HIGH); // Turn ON brake light
  } 
  else {
    brakePressed = false;
    digitalWrite(8, LOW);  // Turn OFF brake light
  }

  // -----------------------------
  // IGNITION + SAFETY CONDITION
  // -----------------------------
  // Start allowed only if:
  // 1. Ignition button pressed
  // 2. Brake pedal pressed
  if (digitalRead(13) == HIGH && brakePressed) {

    engineActive = true; // Enter Ready-to-Drive Mode

    // -----------------------------
    // RTDS (Buzzer) Logic
    // -----------------------------
    // Sound buzzer only once during activation
    if (!buzzerDone) {
      buzzerDone = true;

      digitalWrite(9, HIGH); // Turn ON buzzer
      delay(2000);           // 2-second sound
      digitalWrite(9, LOW);  // Turn OFF buzzer
    }

    // -----------------------------
    // MOTOR ACTIVATION
    // -----------------------------
    digitalWrite(11, HIGH); // Activate motor relay (AIR)
  }

  // -----------------------------
  // TSAL LOGIC
  // -----------------------------
  // TSAL remains ON when system is active
  if (engineActive) {
    digitalWrite(10, HIGH);
  }
}
