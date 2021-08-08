/*
 * MRIIRS Final Year Project 2020-2021
 * 
 * Two Arduino Nano boards are used in this project.
 * This code runs on the board connected to:
 * HC-SR04 Ultrasonic Module
 * LM393 Optical Photosensitive LDR light sensor module
 * MPU 6050 3Axis accelerometer and gyroscope sensor
 * 
 */

#include <Arduino.h>
#include <TinyMPU6050.h>  //Library for getting readable data from MPU6050 

MPU6050 mpu (Wire);  //Constructing MPU-6050

int ldr_pin=3;  //LDR module input pin
 const int trig_pin=5;  //Trigger pin for ultrasonic module
 const int echo_pin=7;  //Echo pin for ultrasonic module
 long distance;
 long duration;
 int LDRvalue;
 int c=0;



void setup() 
{
  pinMode(9,OUTPUT);

  /*This pin will be used to indicate a fall.
   *It is connected to pin 13 on the other board. 
   */

  digitalWrite(9,LOW);
  pinMode(11,INPUT);

  /*
   * This pin will recieve confirmation of location sending.
   * It is connected to pin 11 on the other board.
   */

  pinMode(ldr_dig,INPUT);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(13,OUTPUT);//Buzzer Control
  digitalWrite(13,LOW);
  Serial.begin(9600);

  mpu.Initialize();  //Initializing MPU 6050 sensor

}

void loop() 
{

  dis();  // sub-routine for HC-SR04 ultrasonic module
  LDR();  // sub-routine for LM393 LDR module
  fall_check();  // sub-routine to check orientation using MPU 6050

}
