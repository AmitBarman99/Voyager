//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% THIS IS VOYAGER %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//      
//      IT IS A TEAM OF TWO ENGINEERING STUDENTS CREATED FOR MAKING A
//      4 WHEELER ROBOT WITH IT'S CUSTOM TRANSMITTER.
//      THIS TEAM WORKS FOR ROBODARSHAN (ROBOTICS SOCIETY OF IIEST SHIBPUR) TO EXPLORE ROBOTICS DOMAIN.
//      
//      MEMBERS - AMIT BARMAN,SOPHOMORE AT IIEST SHIBPUR,ETC'25
//                SOUVIK NATH,SOPHOMORE AT IIEST SHIBPUR,ME'25
//                VINIT RANJAN,SOPHOMORE AT IIEST SHIBPUR,CST'25
//                MD SUHAIL AZAM,SOPHOMORE AT IIEST SHIBPUR,ETC'25
//      
//      IN OUR PROJECT WE ARE GOING TO USE -
//        1. AN ARDUINO UNO (FOR RECEIVER)
//        2. AN ARDUINO NANO (FOR TRANSMITTER)
//        3. 2 x NRF24LO1+PA+LNA MODULE
//        4. 2 x JOYSTICKS
//        5. 4 x BO MOTORS
//        6. L298N MOTOR DRIVER
//        7. BATTERY
//    
//       THIS PROGRAM WILL BE STORED IN TRANSMITTER'S ARDUINO.
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#include<nRF24L01.h>
#include<RF24.h>
#include<SPI.h>

RF24 radio(9,10);   //CE and CSN pin
const byte pipeaddress[6]="00001";    //same as receiver code
char receiveData[100]="";
int joystick[2];

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipeaddress);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();

}

void loop() {
  joystick[0]=analogRead(A3);    // A4 pin
  joystick[1]=analogRead(A4);   // A3 pin
  Serial.println(joystick[0]);
  Serial.println(joystick[1]);
  radio.write(joystick,sizeof(joystick));
}
