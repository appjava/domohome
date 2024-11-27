

void initWiFi() {   // ----- WifiMode -------
  Serial.println("");
  Serial.println("Connecting Wifi ");
  Serial.println("");
  #define WIFI_SSID "meSSID"
  #define WIFI_PASS "mePASS"

  // Set your Static IP address
  IPAddress local_IP(192, 168, 0, 130);
  IPAddress gateway(192, 168, 0, 1);
  IPAddress subnet(255, 255, 255, 0);
  
  //WiFi.mode(WIFI_STA);
  WiFi.config(local_IP, gateway, subnet);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
 
     // Configures static IP address
  /*if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }*/
  
  // Wait for connection
  int conect = 0;
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED and conect < 30) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    conect++;
    Serial.println(conect);
    }
    
  if (WiFi.status() == WL_CONNECTED){
    Serial.println("");
    Serial.print("CONECTADO MODO WIFI");
    modo = "Conectado a Wifi";
  
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(WIFI_SSID);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("");
  
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(pilo, HIGH);}
  else {
    Serial.println("");
    Serial.println("NO CONECTADO A WIFI");
    digitalWrite(pilo, LOW);
    modo = "NOT Wifi";}
}

void initSTA() {    // ----- StationMode -------
  
  //--------AccessPoint---
  #ifndef APSSID
  #define APSSID "EchoDomoticCenter"
  #define APPSK  "14de1423fa"
  #endif
  //-----------------------

  const char* ssid = APSSID;
  const char* password = APPSK;

  Serial.println("");
  Serial.print("Configuring access point...");
  //WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  Serial.println("");
  Serial.println("OPERANDO EN MODO ESTACIÓN");

  digitalWrite(LED_BUILTIN, HIGH);
  //digitalWrite(pilo, HIGH);
}
