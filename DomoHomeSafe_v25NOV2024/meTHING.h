

void thingS(){    // ----- Write in ThingSpeak -------

  String UploadData  = "?api_key="+writeApiKey;
         UploadData += "&field1="+String(statusVOL);
         UploadData += "&field2="+String(FUEL);
  String httpRequest = meHost +"/update" + UploadData;
  
  Serial.println("HTTP POST to send: ");
  Serial.println(httpRequest);

  delay(100);

}
