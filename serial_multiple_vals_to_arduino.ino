//works with this p5 sketch:
//https://editor.p5js.org/jesse_harding/sketches/w02SNneXz

//variable to hold incoming data
String incomingData = "01!";

void setup() {
  //set pinmodes
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
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
  digitalWrite(2, HIGH); // Turn LED ON
 }
 else if (incomingData.substring(0,1) == "0"){
  digitalWrite(2, LOW); // Turn LED OFF
 }
 
 if (incomingData.substring(1,2) == "1") {
  digitalWrite(3, HIGH); //Turn LED ON
 } 
 else if (incomingData.substring(1,2) == "0") {
  digitalWrite(3, LOW); //Turn LED OFF
 } 
}
