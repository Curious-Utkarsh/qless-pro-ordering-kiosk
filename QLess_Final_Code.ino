#include <SPI.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <JPEGDecoder.h>
#include <WiFiManager.h>
#include <FS.h>
#include <SPIFFS.h>
#include <MFRC522.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

//MFRC 522
//#define RST_PIN         22          
//#define SS_PIN          21         

//Buttons
#define nextPin   16 //RX2 //INPUT_PULLUP
#define selPin    27 //D27 //INPUT_PULLUP
#define prevPin   32 //D32 //INPUT_PULLUP
#define backPin   12 //D32 //INPUT_PULLUP

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
byte st = 0;

String currentTime = "";
String currentDate = "";
byte hh = 0;
byte mm = 0;

byte bValue = 0;
byte cartPointer = 0;

String menuData = "";

//Item
String beverage[6] = {"Frooti", "Slice", "Nimboos"};
String snacks[6];
String lunch[6];
String icecream[6];

//Cost
String beverageC[6] = {"10", "20", "30"};
String snacksC[6];
String lunchC[6];
String icecreamC[6];

String dataItem = "";
String dataCost = "";

byte spritePosn = 1; // to select order category
byte arrLength = 0; //length of selected category array
byte arrCnt = 0; //which item you chose in array
byte quantity = 1; //selected item quantity
byte cart = 0; //cart line spacing


WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800);

TFT_eSPI tft = TFT_eSPI();

void setup()
{
  Serial.begin(115200);
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
  
  tft.init();
  tft.setRotation(3);  
  if (!SPIFFS.begin()) 
  {
    while (1) yield();
  }

  getData();
  delay(2000);

//  mfrc522.PCD_Init();   // Init MFRC522
//  delay(4000);
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
  }
}
