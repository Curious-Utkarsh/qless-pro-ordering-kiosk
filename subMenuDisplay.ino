void subMenuDisplay()
{
  if(c == 1)
  {
    int f = 0;
    c = 3;
    tft.fillScreen(TFT_BLACK);
    frame(TFT_RED);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);
    
    if(spritePosn == 1)
    {
      tft.fillRoundRect(10, 9, 300, 24, 8, TFT_ORANGE);
      tft.drawCentreString("BEVERAGE", tft.width()/2, 14, 1);

      //tft.print(dataItem);
      for(int i = 0; i<6; i++)
      {
        tft.setCursor(25,(50+(f*25)));
        if(beverage[i] != "")
        {
          tft.print(beverage[i]);
          f++;
        }
      }
      f = 0;
      
      for(int i = 0; i<6; i++)
      {
        tft.setCursor((tft.width()-75),(50+(f*25)));
        if(beverageC[i] != "")
        {
          tft.print(beverageC[i]+"/-");
          f++;
        }
      }
      arrLength = f;
      f = 0;
      for(int i = 0; i < arrLength; i++) //for printing the dots
      {
        tft.fillCircle((tft.width()-100), 57+(i*25), 5, TFT_WHITE);
      }
    }
    if(spritePosn == 2)
    {
      tft.fillRoundRect(10, 9, 300, 24, 8, TFT_ORANGE);
      tft.drawCentreString("MEAL", tft.width()/2, 14, 1);
    }
    if(spritePosn == 3)
    {
      tft.fillRoundRect(10, 9, 300, 24, 8, TFT_ORANGE);
      tft.drawCentreString("SNACKS", tft.width()/2, 14, 1);
    }
    if(spritePosn == 4)
    {
      tft.fillRoundRect(10, 9, 300, 24, 8, TFT_ORANGE);
      tft.drawCentreString("ICE-CREAM", tft.width()/2, 14, 1);
    }
  }
  subMenuCursor();
  if(digitalRead(selPin) == LOW)
  {
    while(digitalRead(selPin) == LOW)
    {}
    delay(100);
    st = 2; //calls qty()
  }
}
