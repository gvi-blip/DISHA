void dis()
{
  /*
   * Object detection and buzzer sound interval  
   * varying with distance.        
   */
  digitalWrite(trig_pin,LOW);
  delay(2);
  digitalWrite(trig_pin,HIGH);
  delay(10);
  digitalWrite(trig_pin,LOW);
  duration=pulseIn(echo_pin,HIGH);
  distance=duration*0.034/2;  //Distance is calculated in centimeters
  
  if(distance<=60 and distance>=30){
    digitalWrite(13,HIGH);
    delay(200); 
    digitalWrite(13,LOW);
    delay(200);
    digitalWrite(13,HIGH);
    delay(200);
    digitalWrite(13,LOW);
  }
  
  if(distance<=30){
    digitalWrite(13,HIGH);
    delay(80);
    digitalWrite(13,LOW);
    delay(80);
    digitalWrite(13,HIGH);
    delay(80);
    digitalWrite(13,LOW);
  }
   
}
