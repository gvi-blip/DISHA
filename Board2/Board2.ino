/*
 * MRIIRS Final Year Project 2020-2021
 * 
 * Two Arduino Nano boards are used in this project.
 * This code runs on the board connected to:
 * UBlox Neo-6M GPS Module
 * Sim 900A GSM Module
 * 
 */

#include <SoftwareSerial.h>  //Software Serial Library
#include <TinyGPS++.h>   //Library by Mikal Hart for decoding NMEA sentences

int RXPin = 4;
int TXPin =7;

//Pin 4 to TX of GPS and 7 to RX

int GPSBaud = 9600;
int s_r=0;  //send or recieve mode flag variable
char s=' ';   //incoming character
int c=0;  //To distinguish between current location request or fall alert

// Create a TinyGPS++ object
TinyGPSPlus gps;

// Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup() {
 
 pinMode(13,INPUT);  //This will recieve the fall interrupt(HIGH) from the other board. 
  pinMode(11,OUTPUT);  //This is connected to pin 11 on the other board
  digitalWrite(11,LOW);
  Serial.begin(9600);
  
  // Start the software serial port at the GPS's default baud
  gpsSerial.begin(GPSBaud);
  rec_init();  //Setting GSM module to SMS recieving mode
  }

void loop() {
  
 
  //Checking if GPS coordinates are availble or not
  while (gpsSerial.available() > 0){
    if (gps.encode(gpsSerial.read())){
      gps_available();
    }
  }
  }
  
