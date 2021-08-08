void gsm_init()
{
  //sub-routine to initialize GSM Module to text sending mode
  
  Serial.println("AT"); //Handshaking with SIM900
  delay(500);
  
 
  Serial.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(500);


  
  Serial.println("AT+CMGS=\"+91**********\"");

  /* 
   * Contact number to which the location is to be sent should be  
   * provided in place of ********* after +91(country code).
   */
  
  delay(500);
  if(c!=1){  //Current location not requested
  send_msg();  //Send fall alert

  }
  
}

void send_msg(){
  /*
   *sub-routine to send fall alert text 
   *with a google map link of current location
   */
  
  Serial.println("Fall alert");
  
  Serial.print("http://maps.google.com/maps?q=");
  Serial.print(gps.location.lat(),6); //Getting latitude
  Serial.print(",");
  Serial.println(gps.location.lng(),6);  //Getting Longitude
  
  Serial.write(26);
  s_r=1;  //Sending mode
  delay(1000);
  
  digitalWrite(11,HIGH);  //Location sent signal to the other board
  delay(1000);
  digitalWrite(11,LOW);

}
