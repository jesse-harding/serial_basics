import processing.serial.*;

Serial myPort;
int potState;
int buttonState;
int[] inputVars = {0, 0}; //make array to be populated from serial (note number of variables) //for multiple variables
//int inputVars; //for a single variable

boolean goodData = false;

void setup () {
  size(200, 200);
  rectMode(CENTER);
  println(Serial.list()); //print serial devices (remember to count from 0)
  myPort = new Serial(this, Serial.list()[1], 9600); //make sure the baudrate matches arduino
  myPort.bufferUntil('\n'); // don't generate a serialEvent() unless you get a newline character
}
void draw () {
  background(0);

  //for multiple variables
  if (goodData){
    potState = inputVars[0];
    buttonState = inputVars[1];
  }
  if (buttonState == 1) {
    fill(color(int(random(255)), int(random(255)), int(random(255))));
  } else {
    fill(255);
  }
  rect(width/2, height/2, map(potState, 0, 1023, 0, width), map(potState, 0, 1023, 0, width));

  //for a single variable

  //analog variable
  //fill(255);
  //rect(width/2, height/2, map(inputVars, 0, 1023, 0, width), map(inputVars, 0, 1023, 0, width));

  //digital variable
  //  if (inputVars == 1){
  //   fill(color(int(random(255)),int(random(255)),int(random(255))));
  // }
  //  else{
  //    fill(255);
  //  }
  //  rect(width/2, height/2, width, height);
}

void serialEvent (Serial myPort) {
  String inString = myPort.readStringUntil('\n'); //read until new line (Serial.println on Arduino)
  if (inString != null) {
    for (int i = 0; i < inString.length(); i++){
      if (inString.charAt(i) == '&'){
        goodData = true;
      }
      if (inString.length() < 3){
        goodData = false;
      }
    }
    inString = trim(inString); // trim off whitespace
    println(inString);
    inputVars = int(split(inString, '&')); // break string into an array and change strings to ints //for multiple variables
    //inputVars = int(inString); //for a single variable
  }
}

void mousePressed(){
  myPort.write("1");
}

void mouseReleased(){
  myPort.write("0");
}
