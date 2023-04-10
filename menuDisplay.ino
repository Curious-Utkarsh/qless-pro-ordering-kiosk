void menuDisplay()
{
  drawJpeg("/snacks.jpg", 20 , 125);
  buttonState();
  drawSprite(spritePosn);
  
  drawJpeg("/icecream.jpg", 170 , 125);
  buttonState();
  drawSprite(spritePosn);

  drawJpeg("/beverage.jpg", 20 , 10);
  buttonState();
  drawSprite(spritePosn);

  drawJpeg("/lunch.jpg", 170 , 10);
  buttonState();
  drawSprite(spritePosn);
}
