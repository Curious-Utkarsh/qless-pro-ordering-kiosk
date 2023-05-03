void yourCart()
{
  if(c == 4)
  {
    c = 5;
    tft.fillScreen(TFT_BLACK);
    frame(TFT_GREEN);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);
    
    tft.fillRoundRect(10, 9, 300, 24, 8, TFT_BLUE);
    tft.drawCentreString("ORDER SUMMARY", tft.width()/2, 14, 1);

    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);

    tft.setCursor(50, tft.height()-40);
    tft.print("ADD ITEM");
    tft.setCursor(tft.width()-50, tft.height()-40);
    tft.print("CHECK OUT");

    if(spritePosn == 1) //Beverage
    {
      tft.setCursor(25,(50+(cart*25)));
      tft.print(beverage[arrCnt]);

      tft.setCursor((tft.width()-120),(50+(cart*25)));
      tft.print(beverageC[arrCnt]+"/-");

      tft.setCursor((tft.width()-70),(50+(cart*25)));
      tft.print(" x "+String(quantity));
      
      cart++; 
    }
  }
  cartCursor();
}
