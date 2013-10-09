#include <Wire.h>
#include <ArduinoNunchuk.h>

#define BAUDRATE 9600
#define X_OFFSET 2
#define Y_OFFSET -8

ArduinoNunchuk nunchuk = ArduinoNunchuk();
int x;
int y;

const int N = 50;
int samples[N];
int n = 0;

void setup()
{
  Serial.begin(BAUDRATE);
  nunchuk.init();
}

void loop()
{
  nunchuk.update();
  
  x = map(nunchuk.analogX, 0, 255, -127, 128) + X_OFFSET;
  y = map(nunchuk.analogY, 0, 255, -127, 128) + Y_OFFSET;
  
  samples[n] = sqrt(x*x+y*y);
  if(n < N) {
      n++;
  } else {
      n = 0;
  }
  
  int sum = 0;
  for(int i=0; i < N; i++) {
      sum += samples[i];
  }
  
  int magnitude = sum/N;
//  float direction = atan2(y,x) + PI/2;
  
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.println(magnitude);
//  Serial.print(",");
//  Serial.println(direction * RAD_TO_DEG);
}
