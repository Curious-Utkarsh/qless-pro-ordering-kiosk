void drawSprite(int cq)
{
  if(cq == 1)//Beverage(spritePosn == 1)
  {
    byte x = 20;
    byte y = 10;
    box(x, y);
  }
  if(cq == 2)//Lunch(spritePosn == 2)
  {
    byte x = 170;
    byte y = 10;
    box(x, y);
  }
  if(cq == 3)//Snacks(spritePosn == 3)
  {
    byte x = 20;
    byte y = 125;
    box(x, y);
  }
  if(cq == 4)//Ice-Cream(spritePosn == 4)
  {
    byte x = 170;
    byte y = 125;
    box(x, y);
  }
}

void box(byte xp, byte yp)
{
  frame(TFT_ORANGE);
  tft.fillRoundRect((xp-5), (yp-5), 5, 115, 8, TFT_WHITE);
  tft.fillRoundRect((xp-5), (yp-5), 140, 15, 8, TFT_WHITE);
  tft.fillRoundRect((xp-5), (yp+95), 140, 14, 8, TFT_WHITE);
  tft.fillRoundRect((xp+130), (yp-5), 5, 115, 8, TFT_WHITE);
}
