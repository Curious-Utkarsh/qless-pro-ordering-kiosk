void qty()
{
  if(c == 3)
  {
    c = 4;
    tft.fillScreen(TFT_BLACK);
    frame(TFT_ORANGE);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);
    
    tft.fillRoundRect(10, 9, 300, 24, 8, TFT_RED);
    tft.drawCentreString("QUANTITY", tft.width()/2, 14, 1);
  }

  nVal = digitalRead(nextPin);
  pVal = digitalRead(prevPin);

  if(pVal == LOW && quantity > 1)
  {
    tft.fillTriangle(80, 105, 80, 135, 40, 120, TFT_RED);
    //tft.fillTriangle((tft.width()-80), (tft.height()-105), (tft.width()-80), (tft.height()-135), (tft.width()-40), (tft.height()-120), TFT_RED);
    while(digitalRead(prevPin) == LOW)
    {}
    delay(100);
    quantity--;
    tft.fillRect(((tft.width()/2)-20), ((tft.height()/2)-30), 100, 80, TFT_BLACK);
  }
  if(nVal == LOW && quantity < 9)
  {
    tft.fillTriangle((tft.width()-80), (tft.height()-105), (tft.width()-80), (tft.height()-135), (tft.width()-40), (tft.height()-120), TFT_RED);
    while(digitalRead(nextPin) == LOW)
    {}
    delay(100);
    quantity++;
    tft.fillRect(((tft.width()/2)-20), ((tft.height()/2)-30), 100, 80, TFT_BLACK);
  } 

  tft.fillTriangle(80, 105, 80, 135, 40, 120, TFT_GREEN);
  tft.fillTriangle((tft.width()-80), (tft.height()-105), (tft.width()-80), (tft.height()-135), (tft.width()-40), (tft.height()-120), TFT_GREEN);
  tft.setCursor(((tft.width()/2)-10), ((tft.height()/2)-20));
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(5);
  tft.print(quantity);

  if(digitalRead(selPin) == LOW)
  {
    while(digitalRead(selPin) == LOW)
    {}
    delay(100);
    st = 3; //calls yourCart()
  }
}
