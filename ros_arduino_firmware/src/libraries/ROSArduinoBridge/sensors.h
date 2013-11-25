/* Functions for various sensor types */

float microsecondsToCm(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per cm.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

long Ping(int pin) {
  long duration, range;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pin, INPUT);
  duration = pulseIn(pin, HIGH);

  // convert the time into meters
  range = microsecondsToCm(duration);
  
  return(range);
}


#ifdef USE_FG
void FG(char cmd){
  
  unsigned int byte1 = 0;
  unsigned int byte2 = 0;
  unsigned int comb = 0;
  
 if (cmd == 1){

  Wire.beginTransmission(FG_Add);
  Wire.write(0x02);
  Wire.endTransmission();
  Wire.requestFrom(FG_Add,2);
  byte1 = Wire.read();
  byte2 = Wire.read();
  comb = ((byte1 << 4));
  comb |= (byte2 >> 4);
  Serial.println(map(comb,0x000,0xFFF,0,100000)/10000.0,4);
  
  
 }
 else if (cmd == 2){
  Wire.beginTransmission(FG_Add);
  Wire.write(0x04);
  Wire.endTransmission();
  Wire.requestFrom(FG_Add,2);
  byte1 = Wire.read();
  byte2 = Wire.read();
  comb = ((byte1 << 8));
  comb |= (byte2);
  Serial.println(map(comb,0x0000,0x6400,0,10000)/100.0,2);

 }
 else { Serial.println("Invalid Arg");} 
  
}
#endif
