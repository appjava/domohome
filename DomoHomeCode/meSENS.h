

void sensorVolt(){    // ----- ReadSensorVolts -------
  int Vsensor = A0;
  pinMode(Vsensor, INPUT);
  float correctionfactor = 7.89; 
  float vout = 0.0; 
  float vin = 0.0; 
  float R1 = 30000;  //   
  float R2 = 5000; //  
  int value = 0;
  
  float xMin=11.7;
  float yMin=0;
  float xMax=12.7;
  float yMax=100;
  float pendiente=(yMax-yMin)/(xMax-xMin);
  float varB=(yMax-(pendiente*xMax));
  float porcent=0.0;
  int capacity=0;
  String fuel="";
  float Tvoltage=0.0;
  float Vvalue=0.0,Rvalue=0.0;
  float RatioFactor=7.17;
  for(unsigned int i=0;i<95;i++){
    Vvalue=Vvalue+analogRead(Vsensor);         //Read analog Voltage
    delay(5);                              //ADC stable
  }
  Vvalue=(float)Vvalue/95.0;            //Find average of 10 values
  Rvalue=(float)(Vvalue/1024.0)*3.09;      //Convert Voltage in 5v factor
  Tvoltage=Rvalue*RatioFactor;          //Find original voltage by multiplying with factor
  
  Serial.print("SYSTEM VOLTAGE = "); 
  Serial.println(Tvoltage);
  porcent=(pendiente*Tvoltage)+(varB);
  statusVOL=(String)Tvoltage;
  capacity=(int)porcent;
  fuel=(String)capacity;
  
  Serial.print("Capacity Storage = "); 
  //Serial.println(porcent);

 //-------------- Energy Capacity -------
  if(capacity<0){
    Serial.println("DISCHARGED!!!");
    FUEL="0";
  }
  else if(capacity>100){
    Serial.println("FULL!!!");
    FUEL="100";
  }
  else{
    Serial.print(capacity);
    Serial.println(" %");
    FUEL=fuel;
  }
  delay(100);
  
//---------------- Voltage Control ----------------
  if(Tvoltage < 11.7){
    digitalWrite(ch6, HIGH);
    statusCh6="CUT OFF";
    statusBAT="AUTO CUT OFF";
  }
  else if(Tvoltage>11.7 and Tvoltage<11.8){
    statusBAT="CUT OFF LOAD!!!";
  }
  else if(Tvoltage>11.8 and Tvoltage<11.9){
    statusBAT="DISCHARGED!";
  }
  else if(Tvoltage>11.9 and Tvoltage<12.0){
    statusBAT="LOWEST!";
  }
  else if(Tvoltage>12.0 and Tvoltage<12.1){
    statusBAT="LOWER!";
  }
  else if(Tvoltage>12.1 and Tvoltage<12.2){
    statusBAT="LOW";
  }
  else if(Tvoltage>12.2 and Tvoltage<12.3){
    statusBAT="MID-LOW";
  }
  else if(Tvoltage>12.3 and Tvoltage<12.4){
    statusBAT="MID";
  }
  else if(Tvoltage>12.4 and Tvoltage<12.5){
    statusBAT="MID-HIGH";
  }
  else if(Tvoltage>12.5 and Tvoltage<12.6){
    statusBAT="HIGH";
  }
  else if(Tvoltage>12.6 and Tvoltage<12.7){
    statusBAT="HIGHER";
  }
  else if(Tvoltage>12.7 and Tvoltage<12.8){
    statusBAT="HIGHEST";
  }
  else if(Tvoltage>12.8 and Tvoltage<13.2){
    statusBAT="SOFT_CHARGE";
  }
  else if(Tvoltage>13.2 and Tvoltage<13.8){
    statusBAT="HARD_CHARGE";
  }
  else if(Tvoltage>13.8 and Tvoltage<14.2){
    statusBAT="MORE LOAD SUPPORTED!";
  }
  else if(Tvoltage>14.2){
    statusBAT="OVER_CHARGE!!!";
    digitalWrite(ch5, LOW);
    statusCh5="ON_Auto";
  }
  delay(100);
  
//--------------------- FlowCH5 --------------------
  if (statusCh5=="ON_Manual"){
    statusCh5="ON_Manual";
    delay(100);
  }
  else if(statusCh5=="ON_Auto"){
    if (Tvoltage<13.2){
      digitalWrite(ch5, HIGH);
      statusCh5="OFF";
      delay(100);
    }
    else{
      statusCh5="ON_Auto";
      delay(100);
    }
  }
  else if(statusCh5=="OFF"){
    statusCh5="OFF";
    delay(100);
  }
  else{
    statusCh5="off";
    delay(100);
  }
}

void readDHT11() {    // ----- Read Sensor DH11-------
  int pinDHT11 = D8;
  SimpleDHT11 dht11;
  byte tempEX = 0;
  byte humEX = 0;
  byte data[40] = {0};
  
  if (dht11.read(pinDHT11, &tempEX, &humEX, data)) {
    return;
  }
  if (isnan(humEX) || isnan(tempEX)) {
      //Serial.println("Failed to read from DHT sensor!");
      Serial.print("// Interior Temperature: ");
      String tEX;
      tEX = "ERR";
      statusTEMP=tEX;
      Serial.println(tEX);
      delay(125);

      Serial.print("/// Interior Humidity: ");
      String hEX;
      hEX = "ERR";
      statusHUM=hEX;
      Serial.println(hEX);
      delay(125);
      return;
   }

  Serial.print(". Temperature: ");
  String tEX;
  tEX = String(tempEX-2);
  statusTEMP=tEX;
  Serial.print(tEX);
  Serial.println(" ºC ");
  delay(125);

  Serial.print(". Humidity: ");
  String hEX;
  hEX = String(humEX);
  statusHUM=hEX;
  Serial.print(hEX);
  Serial.println(" %");
  delay(125);
}
