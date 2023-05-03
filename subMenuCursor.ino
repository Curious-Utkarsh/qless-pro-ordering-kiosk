void subMenuCursor()
{
  nVal = digitalRead(nextPin);
  pVal = digitalRead(prevPin);

  if(pVal == LOW && arrCnt > 0)
  {
    while(digitalRead(prevPin) == LOW)
    {}
    delay(100);
    arrCnt--;
  }
  if(nVal == LOW && (arrCnt < (arrLength-1)))
  {
    while(digitalRead(nextPin) == LOW)
    {}
    delay(100);
    arrCnt++;
  }
  
  tft.fillCircle((tft.width()-100), 57+(arrCnt*25), 5, TFT_GREEN);
  tft.fillCircle((tft.width()-100), 57+(arrCnt*25), 5, TFT_WHITE);
}
