void jsonParse()
{
  if(menuData != "")
  {
    // Allocate JsonBuffer
    const size_t capacity = JSON_ARRAY_SIZE(5) + JSON_OBJECT_SIZE(11) + 60;
    DynamicJsonBuffer jsonBuffer(capacity);
  
   // Parse JSON object
    JsonObject& root = jsonBuffer.parseObject(menuData);
    if (!root.success()) 
    {
      Serial.println(F("Parsing failed!"));
    }
    else
    {
      // Decode JSON/Extract values
      Serial.println(F("Response:"));
      Serial.println(root["id"].as<String>());
      Serial.println(root["title"].as<String>());
      Serial.println(root["description"].as<String>());
      Serial.println(root["rating"].as<String>());

      String title = (root["title"].as<String>());
      Serial.println("NAME OF PHONE IS : "+ title);
    }
  }
  else
  {
    Serial.println("Error in response");
  }
  
  menuData = "";
}

//{"id":1,"title":"iPhone 9","description":"An apple mobile which is nothing like apple","price":549,"discountPercentage":12.96,"rating":4.69,"stock":94,"brand":"Apple","category":"smartphones","thumbnail":"https://i.dummyjson.com/data/products/1/thumbnail.jpg","images":["https://i.dummyjson.com/data/products/1/1.jpg","https://i.dummyjson.com/data/products/1/2.jpg","https://i.dummyjson.com/data/products/1/3.jpg","https://i.dummyjson.com/data/products/1/4.jpg","https://i.dummyjson.com/data/products/1/thumbnail.jpg"]}
