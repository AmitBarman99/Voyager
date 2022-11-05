//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% THIS IS VOYAGER %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//      
//      IT IS A TEAM OF TWO ENGINEERING STUDENTS CREATED FOR MAKING A
//      4 WHEELER ROBOT WITH IT'S CUSTOM TRANSMITTER.
//      THIS TEAM WORKS FOR ROBODARSHAN (ROBOTICS SOCIETY OF IIEST SHIBPUR) TO EXPLORE ROBOTICS DOMAIN.
//      
//      MEMBERS - AMIT BARMAN,SOPHOMORE AT IIEST SHIBPUR,ETC'25
//                SOUVIK NATH,SOPHOMORE AT IIEST SHIBPUR,ME'25
//      
//      IN OUR PROJECT WE ARE GOING TO USE -
//        1. AN ARDUINO UNO (FOR RECEIVER)
//        2. AN ARDUINO NANO (FOR TRANSMITTER)
//        3. 2 x NRF24LO1+PA+LNA MODULE
//        4. 2 x JOYSTICKS
//        5. 4 x 1000RPM DC MOTORS
//        6. L298N MOTOR DRIVER
//        7. BATTERY
//
//       THIS PROGRAM WILL BE STORED IN RECEIVER'S ARDUINO.
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#include<nRF24L01.h>  //include nrf24l01 library
#include<RF24.h>  //include rf24 library
#include<SPI.h> //SPI serial communication
//define motor driver 4 in pin
#define in1 7
#define in2 10
#define in3 9
#define in4 8
//define enA,enB pin
#define EnA 3
#define EnB 4

void setup() {
  // put your setup code here, to run once:
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
