//import the serial libary for use in your sketch
import processing.serial.*;

//declare Serial object
Serial myPort;

//declare variables to store incoming variables (potentiometer and button from Arduino) 
int potState;
int buttonState;

int[] inputVars = {0, 0}; //make array to be populated from serial for 2 variables
//int inputVars; //for a single variable



void setup () {
  //make a sketch that is 200px by 200px
  size(200, 200);
  
  //rectMode() function sets how rectangles are drawn to the screen. the mode CENTER lets us define the x and y coordinates of the center, rather than the default of the upper left corner
  rectMode(CENTER);
  
  //print our available serial ports to the console. look for one that matches the port in the Arduino IDE and count to to determine the index of the proper port
  println(Serial.list()); //(remember to count starting from 0)
  
  //define which port we will be using (change the number in the square brackets to match the index of the proper port)
  myPort = new Serial(this, Serial.list()[1], 9600); //make sure the baudrate matches arduino
  
  myPort.bufferUntil('\n'); // don't generate a serialEvent() unless you get a newline character
}

void draw () {
  background(0);

  //for multiple variables
  if (inputVars.length > 1){
     if (inputVars[1] == 1) { //if button is pressed, the fill in processing will randomize every time the draw function runs
       fill(color(int(random(255)), int(random(255)), int(random(255)))); 
     }
    else {
      fill(255); //otherwise fill is set to white
    }
  }
  rect(width/2, height/2, map(inputVars[0], 0, 1023, 0, width), map(inputVars[0], 0, 1023, 0, width)); //draw the rectangle at a size based on potentiometer data





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
    inString = trim(inString); // trim off whitespace
    println(inString);
    inputVars = int(split(inString, '&')); // break string into an array and change strings to ints //for multiple variables
   
    //the two different sensors connected to Arduino are put into our inputVars array
    potState = inputVars[0];
    buttonState = inputVars[1];
    
    //inputVars = int(inString); //for a single variable
  }
}

void mousePressed(){
  myPort.write("1");
}

void mouseReleased(){
  myPort.write("0");
}
