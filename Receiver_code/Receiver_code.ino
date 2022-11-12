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

RF24 radio(5,6);    //CE,CSN
const byte pipe_address[20]="0001202002"; // transmitter pipe address
int X,Y;
int mS1=0,mS2=0,joystick[2];  //motor speed 1&2 declearation
char receiveData[100]="";

void setup() {  // run onetime
  pinMode(EnA,OUTPUT);
  pinMode(EnB,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  
  //start serial communication
  Serial.begin(9600); //port 9600
  radio.begin();
  radio.openReadingPipe(0,pipe_address);
  radio.startListening();

  //at first all the in pin should be at low
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void loop() {
  if(radio.available()){    //if signal is available
    radio.read(joystick,sizeof(joystick));  //joystick value and it's size
    radio.read(&receiveData,sizeof(receiveData)); //receivedata address and it's size
    Y=joystick[0];
    X=joystick[1];    // these value may be changed accoring to our circuit configeration

  }

    // joystick's value configeration along Y-axis--
    //0      512       1024
  if(Y<490){
    // Moving backward direction (using approximation)
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);

    mS1=map(Y,490,0,0,255);
    mS2=map(Y,490,0,0,255);
  }
  else if(Y>540){
    // Moving forward direction (using approximation)
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);

    mS1=map(Y,540,1023,0,255);  //value btn 0 to 255
    mS2=map(Y,540,1023,0,255);
  }
  else{
    mS1=0;
    mS2=0;
  }
  
  if (X>540){
    int i=map(X,540,1023,0,255);
    mS1=mS1+i;
    mS2=mS2-i;
    if (mS1>255)
    {
      mS1=255;
    }
    if (mS2<0)
    {
      mS2=0;
    } 
  }
  
  if(X<490){
    int i=map(X,490,0,0,255); //increment/decrement factor
    mS1=mS1-i;
    mS2=mS2+i;
    if (mS1<0)
    {
      mS1=0;
    }
    if (mS2>255)
    {
      mS2=255;
    } 
  }

  analogWrite(EnA,mS1);
  analogWrite(EnB,mS2);
  
}
