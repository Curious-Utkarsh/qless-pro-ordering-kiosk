void buttonState()
{
  nVal = digitalRead(nextPin);
  sVal = digitalRead(selPin);
  pVal = digitalRead(prevPin);

  if(pVal == LOW && (cursorPosn > 0 || spritePosn > 1 || arrCnt > 0))
  {
    while(digitalRead(prevPin) == LOW)
    {}
    delay(100);
    cursorPosn--;
    spritePosn--;
  }
  if(nVal == LOW && (cursorPosn < 2 || spritePosn < 4 || arrCnt < (arrLength-1)))
  {
    while(digitalRead(nextPin) == LOW)
    {}
    delay(100);
    cursorPosn++;
    spritePosn++;
  }
  if(sVal == LOW)
  {
    while(digitalRead(selPin) == LOW)
    {}
    delay(100);
    if(currentPage == -2) //homePage
    {
      if(cursorPosn == 0)
      {
        currentPage = 1;//Selection Mode
        c = 0;
      }
      if(cursorPosn == 1)
      {
        currentPage = 2;//Add Money
        c = 0;
      }
      if(cursorPosn == 2)
      {
        currentPage = 3;//Check balance
        c = 0;
      }
  }
  if(currentPage == 1)// Selection Page
  { 
    if(bValue == 1)
    st = 1; //Stepper Motor for Selection Mode

    if(bValue == 0)
    bValue = 1;
  }
  }
}
