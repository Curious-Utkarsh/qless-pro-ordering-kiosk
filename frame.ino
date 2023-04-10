void frame(int color) // PAGE BORDER
{
  tft.fillRect(0, 0, 320, 5, color);
  tft.fillRect(0, 0, 5, 240, color);
  tft.fillRect(315, 0, 5, 240, color);
  tft.fillRect(0, 235, 320, 5, color);
}
