void startScreen()
{
  tft.fillRoundRect(60, 180, 200, 40, 8, TFT_RED);
  tft.drawRoundRect(60, 180, 200, 40, 8, TFT_WHITE);

  tft.fillRoundRect(60, 130, 200, 40, 8, TFT_RED);
  tft.drawRoundRect(60, 130, 200, 40, 8, TFT_WHITE);

  tft.fillRoundRect(60, 80, 200, 40, 8, TFT_RED);
  tft.drawRoundRect(60, 80, 200, 40, 8, TFT_WHITE);

  if(c == 1)
  {
    c = 3;
    tft.setTextSize(2);
    tft.fillRoundRect(10, 10, 300, 32, 8, TFT_GREEN);
    tft.setTextColor(TFT_WHITE);
    tft.drawCentreString("-- SELECT OPTION --", tft.width()/2, 20, 1);
  }

  tft.setCursor(4, 50);
  tft.setTextSize(2);
  tft.setTextColor(TFT_ORANGE);
  tft.print("       -- Q'Less --       ");

  tft.setTextColor(TFT_WHITE);
  tft.setCursor(63, 195);
  tft.print("  CHECK-BALANCE");

  tft.setCursor(78, 145);
  tft.print("  ADD-MONEY");

  tft.setCursor(80, 95);
  tft.print(" PLACE-ORDER");
}
