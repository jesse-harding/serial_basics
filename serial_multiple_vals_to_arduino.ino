//works with this p5 sketch:
//https://editor.p5js.org/jesse_harding/sketches/w02SNneXz

//variable to hold incoming data
String incomingData = "01!";
int ledPin1 = 6;
int ledPin2 = 11;

void setup() {
  //set pinmodes
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  
  //set baudrate for serial communication
  Serial.begin(9600);
}

void loop() {
  
//  check to see if there is a connection 
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    //if so, read the incoming data
    incomingData = Serial.readStringUntil('!'); // Reads the data from the serial port
  }

incomingData.trim();


 Serial.println(incomingData);
 if (incomingData.substring(0,1) == "1") {
  digitalWrite(ledPin1, HIGH); // Turn LED ON
 }
 else if (incomingData.substring(0,1) == "0"){
  digitalWrite(ledPin1, LOW); // Turn LED OFF
 }
 
 if (incomingData.substring(1,2) == "1") {
  digitalWrite(ledPin2, HIGH); //Turn LED ON
 } 
 else if (incomingData.substring(1,2) == "0") {
  digitalWrite(ledPin2, LOW); //Turn LED OFF
 } 
}
