
WiFiClientSecure client;
AsyncWebServer serveR(80);

void InitServer(){
//------------------------- serveR -------------------------
  serveR.on("/", HTTP_GET, [](AsyncWebServerRequest *request){request->send_P(200, "text/html", index_html, processor);});
  
  serveR.on("/onch1", HTTP_GET, [](AsyncWebServerRequest *request){
    //digitalWrite(ch1, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    statusCh1="ON";
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });
  serveR.on("/offch1", HTTP_GET, [](AsyncWebServerRequest *request){
    //digitalWrite(ch1, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    statusCh1="OFF";
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });

  serveR.on("/onch2", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ch2, LOW);
    statusCh2="ON";
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });
  serveR.on("/offch2", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ch2, HIGH);
    statusCh2="OFF";
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });
  
  serveR.on("/onch3", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ch3, LOW);
    statusCh3="ON";
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });
  serveR.on("/offch3", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ch3, HIGH);
    statusCh3="OFF";
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });
    
  serveR.on("/bat", HTTP_GET, [](AsyncWebServerRequest *request){
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });
  serveR.on("/fuel", HTTP_GET, [](AsyncWebServerRequest *request){
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });

  serveR.on("/temp", HTTP_GET, [](AsyncWebServerRequest *request){
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });
  serveR.on("/hum", HTTP_GET, [](AsyncWebServerRequest *request){
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });
    
  serveR.on("/onAll", HTTP_GET, [](AsyncWebServerRequest *request){
    //digitalWrite(ch6, LOW);
    //statusCh6="ON";
    //digitalWrite(ch5, LOW);
    //statusCh5="ON";
    //digitalWrite(ch4, LOW);
    //statusCh4="ON";
    digitalWrite(ch3, LOW);
    statusCh3="ON";
    digitalWrite(ch2, LOW);
    statusCh2="ON";
    //digitalWrite(ch1, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    statusCh1="ON";
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });
  
  serveR.on("/offAll", HTTP_GET, [](AsyncWebServerRequest *request){
    //digitalWrite(ch6, HIGH);
    //statusCh6="OFF";
    //digitalWrite(ch5, HIGH);
    //statusCh5="OFF";
    //digitalWrite(ch4, HIGH);
    //statusCh4="OFF";
    digitalWrite(ch3, HIGH);
    statusCh3="OFF";
    digitalWrite(ch2, HIGH);
    statusCh2="OFF";
    //digitalWrite(ch1, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    statusCh1="OFF";
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
    });

  serveR.on("/sensors", HTTP_GET, [](AsyncWebServerRequest *request){
    AsyncResponseStream *response = request->beginResponseStream("application/json");
    //AsyncWebServerResponse *response = request->beginResponse(200);
    response->addHeader("Access-Control-Allow-Origin", "*");
    
    StaticJsonDocument<1023> json;
    json["Voltage"] = statusVOL;
    json["Capacity"] = FUEL;
    json["Charge"] = statusBAT;
    json["||"] = "||";
    json["CH1"] = statusCh1;
    json["CH2"] = statusCh2;
    json["CH3"] = statusCh3;

    //String jsonString;
    //serializeJson(json, jsonString);
    
    serializeJson(json, *response);
    
    //response->addHeader("application/json",jsonString);
    request->send(response);

    //request->send(200, "application/json", jsonString);
    //request->send(200, "text/plain", jsonString);

    });

    serveR.on("/send", HTTP_GET, [](AsyncWebServerRequest *request){
    Serial.println("Sending Telegram Message");
    AsyncWebServerResponse *response = request->beginResponse(303);
    response->addHeader("Location","/");
    request->send(response);
  });

//------------------------------------------------
  serveR.begin();
  Serial.println("HTTP server started");
  
}
