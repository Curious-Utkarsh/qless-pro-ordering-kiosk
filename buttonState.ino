void buttonState()
{
  nVal = digitalRead(nextPin);
  sVal = digitalRead(selPin);
  pVal = digitalRead(prevPin);

  if(pVal == LOW && (cursorPosn > 0 || spritePosn > 1))
  {
    while(digitalRead(prevPin) == LOW)
    {}
    cursorPosn--;
    spritePosn--;
  }
  if(nVal == LOW && (cursorPosn < 2 || spritePosn < 4))
  {
    while(digitalRead(nextPin) == LOW)
    {}
    cursorPosn++;
    spritePosn++;
  }
  if(sVal == LOW)
  {
    while(digitalRead(selPin) == LOW)
    {}
    if(currentPage == -2) //homePage
    {
      if(cursorPosn == 0)
      {
        currentPage = 1;//Timer Mode
        c = 0;
      }
      if(cursorPosn == 1)
      {
        currentPage = 2;//Selection Mode
        c = 0;
      }
      if(cursorPosn == 2)
      {
        currentPage = 3;//Refill Mode
        c = 0;
      }
  }
  if(currentPage == 2)// Selection Page
  {
//    if(bValue == 1)
//    stepperSelect(); //Stepper Motor for Selection Mode
//
//    if(bValue == 0)
//    bValue = 1;
  }
  }
//  if(bVal == LOW && currentPage != -2)
//  {
//    while(digitalRead(backPin) == LOW)
//    {}
//    currentPage = 0;
//    cnt = 0;
//    bValue = 0;
//  }
}
