void rec_init()
{
  /*
   * sub-routine to initalize GSM module to SMS recieving mode
   */ 

  Serial.println("AT"); //Handshaking with SIM900
  delay(500);

  Serial.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(500);

  Serial.println("AT+CNMI=1,2,0,0,0");  //Configuring text receiving mode
  delay(500);
  
}

void rec_msg(){
  
if(Serial.available()>0){  //Checking for incoming text
    s=Serial.read();  

    if(s=='a'){  //If the text is 'a'
      c=1;  //Current location requested
      gsm_init();  //Initializing GSM module to SMS sending mode
      
      
      Serial.println("Current Location");  
      Serial.print("http://maps.google.com/maps?q=");
    
      Serial.print(gps.location.lat(),6);  //Getting latitude
      Serial.print(",");
      Serial.println(gps.location.lng(),6);  //Getting Longitude
  
      Serial.write(26);
      s_r=1;  //GSM module in sending mode
      c=0;  //Current location sent
      
    }
  }

}
