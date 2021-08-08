void LDR()
{
  /*
   * LM393 provides logic level low when the light incident 
   * is of greater intensity than the set threshold.
   */
  int ldr_stat=digitalRead(ldr_dig);
  Serial.println(ldr_stat);
  if(ldr_stat==0)  {// Light intenstiy higher than threshold
    digitalWrite(13,HIGH);
    delay(700);
    digitalWrite(13,LOW);
    }
 
}
