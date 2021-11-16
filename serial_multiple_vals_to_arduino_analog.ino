//works with this p5 sketch:
//https://editor.p5js.org/jesse_harding/sketches/PguXV19U4

//variable to hold incoming data
String incomingData = "01!";

void setup() {
  //set pinmodes
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);
  
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

analogWrite(11, incomingData.substring(0,3).toInt());
analogWrite(6, incomingData.substring(3,6).toInt());

 
 if (incomingData.substring(0,1) == "1") {
  digitalWrite(12, HIGH); // Turn LED ON
 }
 else if (incomingData.substring(0,1) == "0"){
  digitalWrite(12, LOW); // Turn LED OFF
 }
 
 if (incomingData.substring(1,2) == "1") {
  digitalWrite(A0, HIGH); //Turn LED ON
 } 
 else if (incomingData.substring(1,2) == "0") {
  digitalWrite(A0, LOW); //Turn LED OFF
 } 
}
