//---------------------- WEB PAGE -------------------------
//<meta http-equiv='refresh' content='0'>
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
  <head>
    <title>SOLAR TABLE</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta http-equiv='refresh' content='12'>
    <style>
      body {
        width: auto;
        font-family: Arial; 
        text-align: center; 
        margin:0px auto; 
        padding-top: 12px;
        color: #9c359a;
        background-color: #121212;
      }
      p {
        margin: 0px;
        border: none 3px white;
      }
      h2 {
        border: none;
        border-bottom: none 3px #391554;
        margin-left: 30%;
        margin-right: 30%;
        margin-top: 0px;
        padding_top: 0px;
        padding-bottom: 0px;
      }
      h4 {
        border: none;
        border-top: none 3px #391554;
        margin-left: 10%;
        margin-right: 10%;
        margin-top: 0px;
        padding-top: 0px;
      }
      #all {
          border: none 3px yellow;
      }
      #ch {
          width: 210px;
          display:inline-block;
          padding: 0px;
          border: none 3px white;
      }
      #sensors {
          width: 330px;
          display:inline-block;
          padding: 0px;
          border: none 3px white;
      }
      #extra {
          width: 240px;
          display:inline-block;
          padding: 0px;
          border: none 3px white;
      }
      #header{
          border-bottom: none;
          padding: 0px;
          margin: 0px;
      }
      #footer{
          border-top: none 3px #eb53e2;
          padding: 0px;
          margin: 0px;
      }
      .button {
        padding: 9px 15px;
        font-size: 30px;
        text-align: center;
        outline: none;
        color: white;
        background-color: #9c359a;
        border: solid 1px #eb53e2;
        border-radius: 3px;
        box-shadow: 0 3px #52c1cd;
        cursor: pointer;
      }  
      .button:hover {
        background-color: #391554;
      }
      .button:active {
        background-color: #58427c;
        box-shadow: 0 3px #52c1cd;
        transform: translateY(3px);
      }
    </style>
  </head>
  <script>
  function ch1(element) {
    var c1 = new XMLHttpRequest();
    if(element.checked) {
      c1.open("GET", "/update?output="+element.id+"&state=1", true);
      }
    else {
      c1.open("GET", "/update?output="+element.id+"&state=0", true);
      }
    c1.send();
  }
  </script>
  <body>
    <div id="header">
    <h2>SolarTable HomeSafe</h2>
    </div>
    <div id="sensors">
    <p><span>BatteryStatus: </span><strong><span id="statebat">%STATEBAT%</span></strong><br>
    <a href="bat"><button class="button"> %STATEVOL% v</button></a>
    <a href="fuel"><button class="button"> %FUEL% </button></a></p>
    </div>
    <br><br>
    <div id="all">
    <div id="ch">
    <p><strong>Bord Led</strong> : <strong> <span id="statech1">%STATECH1%</span> </strong></p>
    <p><a href="onch1"><button class="button">ON</button></a>
        <a href="offch1"><button class="button">OFF</button></a></p>
    </div>
    <div id="ch">
    <p><strong>Charger</strong> : <strong> <span id="statech2"> %STATECH2% </span> </strong></p>
    <p><a href="onch2"><button class="button">ON</button></a>
        <a href="offch2"><button class="button">OFF</button></a></p>
    </div>
    <div id="ch">
    <p><strong>Loads</strong> : <strong> <span id="statech3"> %STATECH3% </span> </strong></p>
    <p><a href="onch3"><button class="button">ON</button></a>
        <a href="offch3"><button class="button">OFF</button></a></p>
    </div>
    </div>
    <br>
    <div id="all">
    <p><strong>ALL LIGHT CHANNELS</strong><strong><span id="statechall"></span></strong></p>
    <p><a href="onAll"><button class="button">ON ALL</button></a>
        <a href="offAll"><button class="button">OFF ALL</button></a></p>
    </div>
    <br><br>
    <div id="footer">
    <h4>Powered by EchoGroup</h4>
    </div>
  </body>
</html>)rawliteral";
//---------------- End Web page ------------------------

//---------------- Start String Processor --------------
String processor(const String & var){
  if(var == "STATECHALL"){
    return statusAll;
  }
  else if(var == "STATECH1"){
    return statusCh1;
  }
  else if(var == "STATECH2"){
    return statusCh2;
  }
  else if(var == "STATECH3"){
    return statusCh3;
  }
  else if(var == "STATEBAT"){
    return statusBAT;
  }
  else if(var == "STATEVOL"){
    return statusVOL;
  }
  else if(var == "FUEL"){
    return FUEL;
  }
  return String();
}
//---------------- End String Processor --------------
