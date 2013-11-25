/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
   
#if defined POLOLU_VNH5019
  /* Include the Pololu library */
  #include "DualVNH5019MotorShield.h"

  /* Create the motor driver object */
  DualVNH5019MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined POLOLU_MC33926
  /* Include the Pololu library */
  #include "DualMC33926MotorShield.h"

  /* Create the motor driver object */
  DualMC33926MotorShield drive;
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) drive.setM1Speed(spd);
    else drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#elif defined DAGU4MOTOR
/* Include the FriedCircuits library */
  #include "Dagu4Motor.h"

  /* Create the motor driver object */
  Dagu4Motor motor1(pwm_a, dir_a, CURRENTA, encA1, encA2); 
  Dagu4Motor motor2(pwm_b, dir_b, CURRENTB, encB1, encB2); 
  Dagu4Motor motor3(pwm_c, dir_c, CURRENTC, encC1, encC2); 
  Dagu4Motor motor4(pwm_d, dir_d, CURRENTD, encD1, encD2); 
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    motor1.begin();
    motor2.begin();
    motor3.begin();
    motor4.begin();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT){
      motor1.setMotorDirection(false);
      motor2.setMotorDirection(true);
     
      motor1.setSpeed(spd);
      motor2.setSpeed(spd);      


    }
    else {

      motor3.setMotorDirection(false);
      motor4.setMotorDirection(true);
     
      motor3.setSpeed(spd);
      motor4.setSpeed(spd); 
  
   }
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }


#else
  #error A motor driver must be selected!
#endif

#endif
