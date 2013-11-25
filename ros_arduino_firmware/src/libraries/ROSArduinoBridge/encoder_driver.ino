/* *************************************************************
   Encoder definitions
   
   Add a "#if defined" block to this file to include support for
   a particular encoder board or library. Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   ************************************************************ */
   
#ifdef USE_BASE

#if defined ROBOGAIA
  /* The Robogaia Mega Encoder shield */
  #include "MegaEncoderCounter.h"

  /* Create the encoder shield object */
  MegaEncoderCounter encoders = MegaEncoderCounter(4); // Initializes the Mega Encoder Counter in the 4X Count mode
  
  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT) return encoders.YAxisGetCount();
    else return encoders.XAxisGetCount();
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT) return encoders.YAxisReset();
    else return encoders.XAxisReset();
  }
#elif defined DAGU4MOTOR
 /* Dagu4Motor Controller\Encoders */
  #include <Encoder.h>
  Encoder motor1E(encA1, encA2); 
  Encoder motor2E(encB1, encB2); 
  
  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT) return motor1E.read();
    else return motor2E.read();
    return 0;
  }
  
  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT) motor1E.write(0);
    else motor2E.write(0);
  }
#else
  #error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif

