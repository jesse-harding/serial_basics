//define pin connected to pushbutton
const int buttonPin = 2;
//define pin connected to potentiometer
const int potPin = A0;
//declare pin connected to LED (we are using the built-in LED)
const int ledPin = 13;

//declare and initialize button state (outgoing on serial connection)
int buttonState = 0;

//declare and initialize potentiometer state (outgoing on serial connection)
int potState = 0;

//declare and initialize LED state (incoming from serial connection)
int state = 0;

void setup() {
// initialize the LED pin as an output:
pinMode(ledPin, OUTPUT);
// initialize the pushbutton pin as an input:
pinMode(potPin, INPUT);
pinMode(buttonPin, INPUT);
Serial.begin(9600);
}

void loop() {
// read the state of the pushbutton value:
potState = analogRead(potPin);
// check if the pushbutton is pressed.
buttonState = digitalRead(buttonPin); //momentary button

//output the two variables to the serial connection with an "&" symbol between (it could be any character of your choosing, as long as the same character is used to split the two variables apart on the other side of the serial connection).
//this ampersand symbol is a delimiter which separates our two variables for decoding.
Serial.print(potState);
Serial.print("&");
Serial.println(buttonState);

  //check to see if there is a connection 
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    //if so, read the incoming data
    state = Serial.read(); // Reads the data from the serial port
 }
 if (state == '0') {
  digitalWrite(ledPin, LOW); // Turn LED OFF
  state = 0;
 }
 else if (state == '1') {
  digitalWrite(ledPin, HIGH); //Turn LED ON
  state = 0;
 } 


}
