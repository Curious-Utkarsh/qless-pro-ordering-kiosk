# Q'Less Pro — Self-Service Ordering Kiosk (ESP32, TFT, RFID)

[![ESP32](https://img.shields.io/badge/MCU-ESP32-E7352C)](https://www.espressif.com/)
[![TFT](https://img.shields.io/badge/UI-TFT__eSPI-555)](https://github.com/Bodmer/TFT_eSPI)

The second stage of my [RFID canteen payment system](https://github.com/Curious-Utkarsh/rfid-canteen-payment-system), built solo in April–May 2023: a self-service kiosk, similar to fast-food ordering screens, with a full-colour TFT menu, order summary and balance screens, and payment by tapping a college ID card.

## Demo

[![NFC-based smart ordering system](https://img.youtube.com/vi/iQ-vjzbL71g/hqdefault.jpg)](https://youtu.be/iQ-vjzbL71g)

## Key features

- TFT menu with images (JPEG from SPIFFS), sub-menus, cart and quantity cursor
- MFRC522 card payment, add-money and check-balance screens
- Wi-Fi setup through WiFiManager, NTP time on bills, menu data fetched as JSON

## Hardware and stack

ESP32 · TFT display · MFRC522 RFID · push buttons — Arduino framework, TFT_eSPI, ArduinoJson, WiFiManager, NTPClient

## Files

`QLess_Final_Code.ino` is the entry point; each screen has its own tab (`menuDisplay`, `subMenuDisplay`, `cartCursor`, `orderSummary`, `placeOrder`, `addMoney`, `checkBalance`, …).

---
[Kumar Utkarsh](https://github.com/Curious-Utkarsh) · [LinkedIn](https://www.linkedin.com/in/kumar-utkarsh-124aab227/) · [Portfolio of builds](https://www.mechamindlabs.com/projects)
