/*
Blink 10 led's.
*/
const int TEMP_PIN       = A0; // Temp analog pin.
const int CLOCK_PIN      = 13; // Clock pin for 17 chip
const int RESET_PIN      = 12; // Clear pin to clear the display.

void setup(){
  pinMode(TEMP_PIN, INPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(RESET_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("startup");
}
//Input data gathering.
int tempReading(){
  int reading = analogRead(TEMP_PIN);
  //float math = (5.0/1023.0) * reading;
  int math = map(reading, 0, 1023, 0, 10);
  Serial.println(math);
  return math; // Sending the maped data.
}
// Drives the led's through the 4017 chip.
void decDriver(){
  for (int count = 0; count < tempReading(); count++){
  digitalWrite(CLOCK_PIN, HIGH);
  delay(1);
  digitalWrite(CLOCK_PIN, LOW);
  delay(10);
  } // Below here we reset the chip.
  digitalWrite(RESET_PIN, HIGH);
  delay(1);
  digitalWrite(RESET_PIN, LOW);
  delay(1);
}

void loop(){
  decDriver();
  //tempReading(); // for testing only.
}
