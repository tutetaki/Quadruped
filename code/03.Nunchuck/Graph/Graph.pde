// This program takes ASCII-encoded strings
// from the serial port at 9600 baud and graphs them. It expects values in the
// range 0 to 1023, followed by a newline, or newline and carriage return
 
import processing.serial.*;
 
Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
 
int w = 800;
int h = 300;
 
void setup () {
    size(w, h);        
   
    println(Serial.list());
    // I know that the first port in the serial list on my mac
    // is always my  Arduino, so I open Serial.list()[0].
    // Open whatever port is the one you're using.
    myPort = new Serial(this, Serial.list()[1], 9600);
    // don't generate a serialEvent() unless you get a newline character:
    myPort.bufferUntil('\n');
    background(0);
}
 
void draw () {
    // everything happens in the serialEvent()
}
 
void serialEvent (Serial myPort) {
    String inString = myPort.readStringUntil('\n');
   
    if (inString != null) {
        inString = trim(inString);
     
        String[] xy = split(inString, ',');
     
        // convert to an int and map to the screen height:
        float x = float(xy[0]); // Use x.
        x = map(x, -127, 128, 0, 100);
     
        float y = float(xy[1]); // Use y.
        y = map(y, -127, 128, 0, 100);
     
        float magnitude = float(xy[2]); // Use magnitude.
        magnitude = map(magnitude, 0, 128, 0, 100);
     
        // draw the line:
        stroke(255,0,0);
        line(xPos, 100, xPos, 100 - x);
     
        stroke(0,255,0);
        line(xPos, 200, xPos, 200 - y);
     
        stroke(0, 0, 255);
        line(xPos, 300, xPos, 300 - magnitude);
     
        if (xPos >= width) {
            xPos = 0;
            background(0); 
        } 
        else {
            xPos++;
        }
    }
}
