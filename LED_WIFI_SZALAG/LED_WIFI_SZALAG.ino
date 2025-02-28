const int buttonPin = 2; // Pin for the button
const int redPin = 3;    // Pin for the red channel
const int greenPin = 5;  // Pin for the green channel
const int bluePin = 6;   // Pin for the blue channel

int buttonState = 0;     // Variable for reading the button status
int colorState = 0;      // Variable to track the current color

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    colorState++;
    if (colorState > 2) {
      colorState = 0;
    }
    delay(200); // Debounce delay
  }

  switch (colorState) {
    case 0:
      setColor(128, 255, 255); // Red
      break;
    case 1:
      setColor(255, 128, 255); // Green
      break;
    case 2:
      setColor(255, 255, 128); // Blue
      break;
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
