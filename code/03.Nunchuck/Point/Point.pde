// This program takes ASCII-encoded strings
// from the serial port at 9600 baud and graphs them. It expects values in the
// range 0 to 1023, followed by a newline, or newline and carriage return
 
import processing.serial.*;
 
Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
 
int w = 400;
int h = 400;
int margin = 0;
int division = 4;
 
void setup () {
   // set the window size:
   size(w, h);        
   
   // List all the available serial ports
   println(Serial.list());
   // I know that the first port in the serial list on my mac
   // is always my  Arduino, so I open Serial.list()[0].
   // Open whatever port is the one you're using.
   myPort = new Serial(this, Serial.list()[1], 9600);
   // don't generate a serialEvent() unless you get a newline character:
   myPort.bufferUntil('\n');
   // set inital background:
   background(0);
}
 
void draw () {
    // draw the axis:
    stroke(255,255,255);
    line(w/2, 0+margin, w/2, h-margin);
    line(0+margin, h/2, w-margin, h/2);
    for (int i = w/2; i <= w; i = i+(w/2-margin)/division)
        line(i, h/2-4, i, h/2+4);
    for (int i = w/2; i > 0; i = i-(w/2-margin)/division)
        line(i, h/2-4, i, h/2+4);
    for (int i = h/2; i <= h; i = i+(h/2-margin)/division)
        line(w/2-4, i, w/2+4, i);
    for (int i = h/2; i > 0; i = i-(h/2-margin)/division)
        line(w/2-4, i, w/2+4, i);
     
    // everything happens in the serialEvent()
}
 
void serialEvent (Serial myPort) {
   // get the ASCII string:
   String inString = myPort.readStringUntil('\n');
   
   if (inString != null) {
       // trim off any whitespace:
       inString = trim(inString);
     
       // separate the three points.
       String[] data = split(inString, ',');
     
       // convert to an int and map to the screen height:
       float x = float(data[0]); // Use x.
       x = map(x, -127, 128, -width/2, width/2);
     
       float y = float(data[1]); // Use y.
       y = map(y, -127, 128, height/2, -height/2);
     
       // draw the line:
       stroke(255,0,0);
       line(width/2, height/2+y, width/2+x, height/2+y);
     
       stroke(0,255,0);
       line(width/2+x, height/2, width/2+x, height/2+y);
     
       stroke(100,100,100);
       line(width/2, height/2, width/2+x, height/2+y);
    }
    if(millis() % 2 == 0) {
        background(0);
    }
}
