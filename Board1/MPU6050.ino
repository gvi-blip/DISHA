void fall_check()
{
  /*
   * X axis of accelerometer is used to check orientation.
   * 1.0g acceleration implies upright position.
   * Acceleration less than 0.60g for some time implies a fall
   * g=Earth's Gravitational force
   */

  int locstatus=0;   
  mpu.Execute();
  float x = mpu.GetAccX();  //Getting X axis acceleration

  if(x<0.60){  //Fall position
    c++;
    }

  if(c==50){  //Fall
    digitalWrite(9,HIGH);  //Fall alert interrupt sent to other board
    delay(1000);
    c=0;

  while(x<0.90){  
    /*Waiting for location delivered confirmation 
     *and upright position of user
     */
    if(digitalRead(11)==HIGH){
      digitalWrite(9,LOW); 
      /*
       * Fall alert is sent.
       * Fall interrupt removed but user is
       * still not upright.
       */
      delay(50);
      locstatus=1; 

    }

    mpu.Execute();
    x=mpu.GetAccX();
    delay(1000);
    
    }

    if(locstatus==0){
    digitalWrite(9,LOW);  //Fall interrupt removed
    delay(1000);
  }
}
}
