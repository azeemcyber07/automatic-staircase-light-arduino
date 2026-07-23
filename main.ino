// =====================================
// Staircase Light using 2 IR Sensors
// BOTH Sensors Working
// 6 LEDs
// =====================================

// LED Pins
const int stepLEDs[6] = {4, 5, 6, 7, 8, 9};

// Sensors
const int bottomSensor = 2;
const int topSensor = 3;

void setup() {

  // LED setup
  for (int i = 0; i < 6; i++) {
    pinMode(stepLEDs[i], OUTPUT);
    digitalWrite(stepLEDs[i], LOW);
  }

  // Sensor setup
  pinMode(bottomSensor, INPUT_PULLUP);
  pinMode(topSensor, INPUT_PULLUP);
}

// =====================================
// BOTTOM → TOP
// =====================================
void runUp() {

  // LEDs ON
  for (int i = 0; i < 6; i++) {
    digitalWrite(stepLEDs[i], HIGH);
    delay(200);
  }

  delay(3000);

  // LEDs OFF
  for (int i = 0; i < 6; i++) {
    digitalWrite(stepLEDs[i], LOW);
    delay(200);
  }
}

// =====================================
// TOP → BOTTOM
// =====================================
void runDown() {

  // LEDs ON reverse
  for (int i = 5; i >= 0; i--) {
    digitalWrite(stepLEDs[i], HIGH);
    delay(200);
  }

  delay(3000);

  // LEDs OFF reverse
  for (int i = 5; i >= 0; i--) {
    digitalWrite(stepLEDs[i], LOW);
    delay(200);
  }
}

// =====================================
// MAIN LOOP
// =====================================
void loop() {

  // Bottom sensor triggered
  if (digitalRead(bottomSensor) == LOW) {

    delay(50);

    if (digitalRead(bottomSensor) == LOW) {

      runUp();

      delay(1000);
    }
  }

  // Top sensor triggered
  if (digitalRead(topSensor) == LOW) {

    delay(50);

    if (digitalRead(topSensor) == LOW) {

      runDown();

      delay(1000);
    }
  }
}
