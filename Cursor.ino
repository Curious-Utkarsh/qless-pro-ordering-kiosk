void Cursor()
{
  tft.fillTriangle(30, (94+(50*cursorPosn)), 30, (110+(50*cursorPosn)), 55, (102+(50*cursorPosn)), TFT_PINK);
  
  if(cursorPosn == 0)
  {
    tft.fillRect(28, 144, 28, 18, TFT_BLACK);//2nd posn
    tft.fillRect(28, 194, 28, 18, TFT_BLACK);//3rd posn
  }
  if(cursorPosn == 1)
  {
    tft.fillRect(28, 94, 28, 18, TFT_BLACK);//1st posn
    tft.fillRect(28, 194, 28, 18, TFT_BLACK);//3rd posn
  }
  if(cursorPosn == 2)
  {
    tft.fillRect(28, 94, 28, 18, TFT_BLACK);//1st posn
    tft.fillRect(28, 144, 28, 18, TFT_BLACK);//2nd posn
  }
}
