void getData()
{
  HTTPClient https;
  Serial.print("[HTTPS] begin...\n");
  https.begin("https://dummyjson.com/products/1"); //HTTPS

  Serial.print("[HTTPS] GET...\n");
  // start connection and send HTTP header
  int httpCode = https.GET();
  // httpCode will be negative on error
  if(httpCode > 0) 
  {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
    // file found at server
    if(httpCode == HTTP_CODE_OK) 
    {
      String payload = https.getString();
      menuData = payload;
      Serial.println(payload);
      Serial.println("\n");
    }
  } 
  else 
  {
    Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
  }
  https.end();

  if(menuData != "")
  {
    // Allocate JsonBuffer
    const size_t capacity = JSON_ARRAY_SIZE(5) + JSON_OBJECT_SIZE(11) + 60;
    DynamicJsonBuffer jsonBuffer(capacity);

    // Parse JSON object
    JsonObject& root = jsonBuffer.parseObject(menuData);

    if (root.success())
    {
      dataItem = (root["title"].as<String>());
      dataCost = (root["id"].as<String>());
    }
  }
}
