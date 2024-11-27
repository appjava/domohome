String file = "DomoHomeSafe_v25NOV2024";

#include "meLIB.h"
#include "meVAR.h"
#include "meRED.h"
#include "meSENS.h"
#include "meWEB.h"
#include "meSER.h"
#include "meTHING.h"

void setup() {    // ----- meSetup -------
  
  Serial.begin(115200);
  WiFi.mode(WIFI_AP_STA);
  
  mePINSet();
  delay(100);
  InitServer();
  delay(100);
  initWiFi();
  delay(100);
  initSTA();
  delay(100);
}

void loop() {   //---------------- meLoop ----------------

  delay(500);

  int tim = 0;
  while (tim < 12) {
    Serial.println("|----------------- Status SolarTable ----------------|");
    Serial.print(modo);
    Serial.print(" // IP address: ");
    Serial.println(WiFi.localIP());
    Serial.print("Lecture Nº: ");
    Serial.println(tim);
    Serial.print("timeOut= ");
    Serial.println(timeOutS);
    sensorVolt();
    delay(500);
    tim++;
    Serial.println("File Loaded: ");
    Serial.println(file);
    Serial.println("|------------------------------------------------|");
    Serial.println("");
    delay(500);
  }

  delay(500);
  
  if (WiFi.status() != WL_CONNECTED){
    initWiFi();
  }
  else{}
  
  delay(100);
  timeOutS++;
  
  if (timeOutS==5){
  Serial.println("|--------------------- Update Channel ThingSpeak ---------------------|"); 
    //thingS();
  Serial.println("|---------------------------------------------------------------------|");
  Serial.println("");
    timeOutS=0;
  }
  else{}

}
