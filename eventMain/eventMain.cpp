/*
By       MAderdash
DATE:    11-17-1021
Licence: BeerWare.
Discription: This is the code for the event in Discord server.


*/
const int pin13      = 13;

void setup(){
  pinMode(pin13, OUTPUT);
  Serial.begin(9600);
  Serial.println("startup");
  
}
void Temp(){
Serial.println("Inside the temp function");
}

void loop(){
  Temp();
  digitalWrite(pin13, HIGH);
  delay(990);
  digitalWrite(pin13, LOW);
  delay(10);
  
}
