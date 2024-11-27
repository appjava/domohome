//----------------- Variables Definition ----------------

int pilo=D9;
int ch3=D7;
int ch2=D6;
int ch1=D5;
int ch6=D4;
int ch5=D3;
int ch4=D2;

String statusCh1="off";
String statusCh2="off";
String statusCh3="off";
String statusCh4="off";
String statusAll="off";

int timeOutS=0;

String jsonString;

String modo = "none";

String statusCh6="off";
String statusCh5="off";
String statusBAT="None";
String statusTEMP="None";
String statusHUM="Zero";
String statusVOL="Zero";
String FUEL="NA";

void mePINSet(){
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(ch6, OUTPUT);
    pinMode(ch5, OUTPUT);
    pinMode(ch4, OUTPUT);
    pinMode(ch3, OUTPUT);
    pinMode(ch2, OUTPUT);
    pinMode(ch1, OUTPUT);
    pinMode(pilo, OUTPUT);
    
    digitalWrite(ch6, HIGH);
    digitalWrite(ch5, HIGH);
    digitalWrite(ch4, HIGH);
    digitalWrite(ch3, HIGH);
    digitalWrite(ch2, HIGH);
    digitalWrite(ch1, HIGH);
}
