//works with this p5 sketch:
//https://editor.p5js.org/jesse_harding/sketches/UUI7a27p8
//tinkercad setup: https://www.tinkercad.com/things/75mjjEGVidv-exquisite-uusam-elzing/editel?sharecode=lSg7WAIixEBa6NFT-GnltZWOZT-jVNwDnl40TJSY85o

//variables for outgoing data
int analogVal;
int digitalVal;
String delimiter = "&";

unsigned long prevMillis = 0; //variable for millis timer

//variable to hold incoming data
int incomingData;

void setup() {
  //set pinmodes
  pinMode(A0, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  //set baudrate for serial communication
  Serial.begin(9600);
}

void loop() {
  //read connected sensors
  analogVal = analogRead(A0);
  digitalVal = digitalRead(2);

  //concatenate sensors with delimiter between (this ampersand will allow p5 to split the two values apart
  if (millis()-prevMillis > 65){ //we need to use a millis timer here to slow down the number of messages from arduino so as not to innundate the browser
  Serial.println(analogVal+delimiter+digitalVal);
  prevMillis = millis();
  }
  
  //check to see if there is a connection 
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    //if so, read the incoming data
    incomingData = Serial.read(); // Reads the data from the serial port
 }
 if (incomingData == '0') {
  digitalWrite(13, LOW); // Turn LED OFF
  incomingData = 0;
 }
 else if (incomingData == '1') {
  digitalWrite(13, HIGH); //Turn LED ON
  incomingData = 0;
 } 
//  delay(10);
}
