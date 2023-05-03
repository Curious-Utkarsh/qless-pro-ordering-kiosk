void cartCursor()
{
  nVal = digitalRead(nextPin);
  pVal = digitalRead(prevPin);

  if(nVal == LOW && cartPointer == 0)
  {
    while(digitalRead(prevPin) == LOW)
    {}
    delay(100);
    cartPointer = 1;
  }
  if(pVal == LOW && cartPointer == 1)
  {
    while(digitalRead(nextPin) == LOW)
    {}
    delay(100);
    cartPointer = 0;
  }
  
  tft.fillCircle((tft.width()-100), 57+(arrCnt*25), 5, TFT_GREEN);
  tft.fillCircle((tft.width()-100), 57+(arrCnt*25), 5, TFT_WHITE);
}
