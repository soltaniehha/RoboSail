// Helpful program to see what the wind sensor is reading.

// This program will print the recieved values, and the corresponding angle,
// to the serial console.

// Pin assignments
const int ROBOSAIL_PIN_WIND = 7; 

int windAngle = 0;
int windPulseWidth = 0;

void setup() {
  Serial.begin(9600);

  // Set RC receiver on digital input pins
  pinMode(ROBOSAIL_PIN_WIND, INPUT);
}

void loop() {
  // Read commanded (manual) values from the RC reciever
  // pulseIn returns the width of the command pulse in microseconds.
  windPulseWidth = pulseIn(ROBOSAIL_PIN_WIND, HIGH, 25000);
  
  // Convert the wind angle to degrees from PWM.  Range -180 to +180
  windAngle = map(windPulseWidth, 0, 1010, 180, -180);
  
  windAngle = constrain(windAngle, -180, 180);

  // Print out the values for debug.
  Serial.print("pulse: ");
  Serial.print(windPulseWidth);
  Serial.print("\tangle: ");
  Serial.print(windAngle);

  Serial.print("\n"); // Print a new line

  // add delay to not overwhelm serial monitor
  delay(500);
}

