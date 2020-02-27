const int buttonPin = 2;
const int potPin = A0;
const int ledPin = 13;

int buttonState = 0;
int potState = 0;

int state = 0;

void setup() {
// initialize the LED pin as an output:
pinMode(ledPin, OUTPUT);
// initialize the pushbutton pin as an input:
//pinMode(buttonPin, INPUT);
pinMode(potPin, INPUT);
pinMode(buttonPin, INPUT);
Serial.begin(9600);
}

void loop() {
// read the state of the pushbutton value:
potState = analogRead(potPin);
// check if the pushbutton is pressed.
buttonState = digitalRead(buttonPin); //momentary button

Serial.print(potState);
Serial.print("&");
Serial.println(buttonState);

  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 if (state == '0') {
  digitalWrite(ledPin, LOW); // Turn LED OFF
  state = 0;
 }
 else if (state == '1') {
  digitalWrite(ledPin, HIGH);
  state = 0;
 } 


}
