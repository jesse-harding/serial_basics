int analogVal;
int digitalVal;
String delimiter = "&";

int incomingData;

void setup() {
  pinMode(A0, INPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogVal = analogRead(A0);
  digitalVal = digitalRead(2);
  Serial.println(analogVal+delimiter+digitalVal);
  
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
}
