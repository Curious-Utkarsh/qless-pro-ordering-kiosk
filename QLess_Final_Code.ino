#include <SPI.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <JPEGDecoder.h>
#include <WiFiManager.h>
#include <FS.h>
#include <SPIFFS.h>

//Buttons
#define nextPin   16 //RX2 //INPUT_PULLUP
#define selPin    27 //D27 //INPUT_PULLUP
#define prevPin   32 //D32 //INPUT_PULLUP

//Led cum buzz 
#define redLed       33 //D33
#define greenLed     25 //D25
#define buzz         3  //RX0

byte c = 0;
int currentPage = 0;
byte cursorPosn = 0; // for startScreen
byte nVal = 0;
byte sVal = 0;
byte pVal = 0;
byte spritePosn = 1; // for placeOrder

String currentTime = "";
String currentDate = "";
byte hh = 0;
byte mm = 0;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800);

TFT_eSPI tft = TFT_eSPI();

void setup()
{
  Serial.begin(115200);
  delay(10);
  SPI.begin();
  delay(10);
  pinMode(prevPin, INPUT_PULLUP);
  pinMode(selPin,  INPUT_PULLUP);
  pinMode(nextPin, INPUT_PULLUP);
  pinMode(redLed,  OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(buzz,    OUTPUT);
  
  WiFi.mode(WIFI_STA);
  WiFiManager wm;
  if(digitalRead(selPin) == LOW)
  {
    wm.resetSettings();
    for(byte i = 0; i<20; i++)
    {
      digitalWrite(redLed, HIGH);
      delay(50);
      digitalWrite(redLed, LOW);
      delay(50);
    }
  }

  bool res;
  res = wm.autoConnect("AutoConnectAP");
  if(!res) 
  {
    //Serial.println("Failed to connect");
    digitalWrite(redLed, HIGH); //means not connected to wifi
  } 
  else 
  {
      //if you get here you have connected to the WiFi    
      //Serial.println("connected...yeey :)");
      digitalWrite(redLed, LOW); //means connected to wifi
  }
  timeClient.begin();
  
  tft.begin();
  tft.setRotation(3);  
  if (!SPIFFS.begin()) 
  {
    while (1) yield();
  }
}

void loop()
{
  //Start Screen
  if(currentPage == 0)
  {
    if(c == 0)
    {
      tft.fillScreen(TFT_BLACK);
      frame(TFT_YELLOW);
      c = 1;
    }
    startScreen();//currentPage = 0
    currentPage = -2;
  }
  
  if(currentPage == -2)
  {
    buttonState();
    Cursor();
  }

  //Place Order
  if(currentPage == 1)
  {
    if(c == 0)
    {
      tft.fillScreen(TFT_PINK);
      frame(TFT_ORANGE);
      box(20, 125);
      box(170, 125);
      box(20, 10);
      box(170, 10);
      c = 1;
    }
    placeOrder();
//    if(digitalRead(backPin) == LOW && currentPage != -2)
//    {
//      while(digitalRead(backPin) == LOW)
//      {}
//      currentPage = 0;
//      c = 0;
//    }
  }

  //Add Money
  if(currentPage == 2)
  {
    if(c == 0)
    {
      tft.fillScreen(TFT_PINK);
      frame(TFT_GREEN);
      c = 1;
    }
    addMoney();
//    if(digitalRead(backPin) == LOW && currentPage != -2)
//    {
//      while(digitalRead(backPin) == LOW)
//      {}
//      currentPage = 0;
//      c = 0;
//    }
  }

  //Check Balance
  if(currentPage == 3)
  {
    if(c == 0)
    {
      tft.fillScreen(TFT_PINK);
      frame(TFT_GREEN);
      c = 1;
    }
    checkBalance();
//    if(digitalRead(backPin) == LOW && currentPage != -2)
//    {
//      while(digitalRead(backPin) == LOW)
//      {}
//      currentPage = 0;
//      c = 0;
//    }
  }
}
