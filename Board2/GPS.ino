void gps_available()
{
  
if (gps.location.isValid())
  {  

   delay(500);
    
   if(digitalRead(13)==HIGH){  //Fall interrupt HIGH indicating a fall 
     
 gsm_init(); //Initializing GSM Module to SMS send mode

   }

   else{   //Upright position
    
if(s_r==1){  // If GSM is in SMS sending mode
      rec_init();  // Set to SMS receiving mode
      rec_msg();   // Check incoming messages  
      s_r=0;  // Indicates GSM is in SMS receiving mode

    }
    
    else{  //If GSM is in receiving mode
      rec_msg();  // Check incoming messages

    }
    
   }
  }
}
