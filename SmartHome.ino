#include <ESP8266WiFi.h>

//const char* ssid     = "free-wifi";
//const char* password = "12342680";

const char* ssid = "UKTC";
const char* password= "uktc1234";


// GPIO16->D0; GPIO5->D1; GPIO4->D2; GPIO0->D3; GPIO2->D4;
// GPIO14->D5; GPIO12->D6; GPIO13->D7; GPIO15->D8;
int pin1 = 16, pin2 = 5, pin3 = 4, pin4 = 0;
int pin5 = 2, pin6 = 14, pin7 = 12, pin8 = 13; 

int value1 = LOW, value2 = LOW, value3 = LOW, value4 = LOW;
int value5 = LOW, value6 = LOW, value7 = LOW, value8 = LOW;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  setPins();
 
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  server.begin();
  Serial.println("Server started");

  Serial.print("http://");
  Serial.print(WiFi.localIP());

}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  /////////////////////////////
  
  //relay1
  if (request.indexOf("/relay=OFF") != -1)  {
    digitalWrite(pin1, HIGH);
    value1 = HIGH;
  } else if (request.indexOf("/relay=ON") != -1)  {
    digitalWrite(pin1, LOW);
    value1 = LOW;
  }
  //.....................................................
  //relay2
  else if (request.indexOf("/relay2=OFF") != -1)  {
        digitalWrite(pin2, HIGH);
        value2 = HIGH;
  } else if (request.indexOf("/relay2=ON") != -1)  {
        digitalWrite(pin2, LOW);
        value2 = LOW;
  }
  //.....................................................
  //relay3
  else if (request.indexOf("/relay3=OFF") != -1)  {
        digitalWrite(pin3, HIGH);
        value3 = HIGH;
  } else if (request.indexOf("/relay3=ON") != -1)  {
        digitalWrite(pin3, LOW);
        value3 = LOW;
  }
  //.....................................................
  //relay4
  else if (request.indexOf("/relay4=OFF") != -1)  {
        digitalWrite(pin4, HIGH);
        value4 = HIGH;
  } else if (request.indexOf("/relay4=ON") != -1)  {
        digitalWrite(pin4, LOW);
        value4 = LOW;
  }
  //.....................................................
  //relay5
  else if (request.indexOf("/relay5=OFF") != -1)  {
        digitalWrite(pin5, HIGH);
        value5 = HIGH;
  } else if (request.indexOf("/relay5=ON") != -1)  {
        digitalWrite(pin5, LOW);
        value5 = LOW;
  }
  //.....................................................
  //relay6
  else if (request.indexOf("/relay6=OFF") != -1)  {
        digitalWrite(pin6, HIGH);
        value6 = HIGH;
  } else if (request.indexOf("/relay6=ON") != -1)  {
        digitalWrite(pin6, LOW);
        value6 = LOW;
  }
  //.....................................................
  //relay7
  else if (request.indexOf("/relay7=OFF") != -1)  {
        digitalWrite(pin7, HIGH);
        value7 = HIGH;
  } else if (request.indexOf("/relay7=ON") != -1)  {
        digitalWrite(pin7, LOW);
        value7 = LOW;
  }
  //.....................................................
  //relay8
  else if (request.indexOf("/relay8=OFF") != -1)  {
        digitalWrite(pin8, HIGH);
        value8 = HIGH;
  } else if (request.indexOf("/relay8=ON") != -1)  {
        digitalWrite(pin8, LOW);
        value8 = LOW;
  }
  //.....................................................
  //HTML-------------------------------------------------
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><title>UKTC Smart house </title>");
  client.println("<style>.button {");
  client.println("background-color: #e7e7e7;");
  client.println("border:1px solid #000000;");
  client.println("color: black;");
  client.println("padding: 7px 7px;");
  client.println("font-size: 16px;");
  client.println("border-radius: 12px;}");
  client.println(".button:hover{");
  client.println("background-color: #d1d1d1;");
  client.println("color: black;}</style></head>");
  client.println("<body bgcolor=#a6ede4>");
  client.println("<h2 align = \"center\">UKTC Smart house v.01</h2>");
  //https://uktc-bg.com/uktc-content/themes/uktc-wp/images/logo.png
  client.println("<h3 align = \"center\"> <img src = http://bit.do/ePCCh  height=\"100\" width=\"100\"></img></h3>");
  client.println("<table align = \"center\">");
  client.println("<tr><td>");
  //relay1
  client.print("Relay1 is now: ");
  if (value1 == HIGH) {
    client.print("<i>Off</i>  ||<br>");
  } else {
    client.print("<i>On</i> ||<br>");
  }
  client.println("<a href=\"/relay=ON\"\"><button class = \"button\"><b>On</b> </button></a>");
  client.println("<a href=\"/relay=OFF\"\"><button class = \"button\"><b>Off</b> </button></a>");
  client.println("<br></br></td>");
  //.....................................................
  //relay2
  client.println("<td>");
  client.print("Relay2 is now: ");
  if (value2 == HIGH) {
    client.print("<i>Off</i><br>");
  } else {
    client.print("<i>On</i><br>");
  }
  client.println("<a href=\"/relay2=ON\"\"><button class = \"button\"><b>On</b> </button></a>");
  client.println("<a href=\"/relay2=OFF\"\"><button class = \"button\"><b>Off</b> </button></a>");
  client.println("<br></br></td></tr>");
  //.....................................................
  //relay3
  client.println("<tr><td>");
  client.print("Relay3 is now: ");
  if (value3 == HIGH) {
    client.print("<i>Off</i>  ||<br>");
  } else {
    client.print("<i>On</i> ||<br>");
  }
  client.println("<a href=\"/relay3=ON\"\"><button class = \"button\"><b>On</b> </button></a>");
  client.println("<a href=\"/relay3=OFF\"\"><button class = \"button\"><b>Off</b> </button></a>");
  client.println("<br></br></td>");
  //.....................................................
  //relay4
  client.println("<td>");
  client.print("Relay4 is now: ");
  if (value4 == HIGH) {
    client.print("<i>Off</i><br>");
  } else {
    client.print("<i>On</i><br>");
  }
  client.println("<a href=\"/relay4=ON\"\"><button class = \"button\"><b>On</b> </button></a>");
  client.println("<a href=\"/relay4=OFF\"\"><button class = \"button\"><b>Off</b> </button></a>");
  client.println("<br></br></td></tr>");
  //.....................................................
  //relay5
  client.println("<tr><td>");
  client.print("Relay5 is now: ");
  if (value5 == HIGH) {
    client.print("<i>Off</i>  ||<br>");
  } else {
    client.print("<i>On</i> ||<br>");
  }
  client.println("<a href=\"/relay5=ON\"\"><button class = \"button\"><b>On</b> </button></a>");
  client.println("<a href=\"/relay5=OFF\"\"><button class = \"button\"><b>Off</b> </button></a>");
  client.println("<br></br></td>");
  //.....................................................
  //relay6
  client.println("<td>");
  client.print("Relay6 is now: ");
  if (value6 == HIGH) {
    client.print("<i>Off</i><br>");
  } else {
    client.print("<i>On</i><br>");
  }
  client.println("<a href=\"/relay6=ON\"\"><button class = \"button\"><b>On</b> </button></a>");
  client.println("<a href=\"/relay6=OFF\"\"><button class = \"button\"><b>Off</b> </button></a>");
  client.println("<br></br></td></th>");
  //.....................................................
  //relay7
  client.println("<tr><td>");
  client.print("Relay7 is now: ");
  if (value7 == HIGH) {
    client.print("<i>Off</i>  ||<br>");
  } else {
    client.print("<i>On</i> ||<br>");
  }
  client.println("<a href=\"/relay7=ON\"\"><button class = \"button\"><b>On</b> </button></a>");
  client.println("<a href=\"/relay7=OFF\"\"><button class = \"button\"><b>Off</b> </button></a>");
  client.println("<br></br></td>");
  //.....................................................
  //relay8
  client.println("<td>");
  client.print("Relay8 is now: ");
  if (value8 == HIGH) {
    client.print("<i>Off</i><br>");
  } else {
    client.print("<i>On</i><br>");
  }
  client.println("<a href=\"/relay8=ON\"\"><button class = \"button\"><b>On</b> </button></a>");
  client.println("<a href=\"/relay8=OFF\"\"><button class = \"button\"><b>Off</b> </button></a>");
  client.println("<br></br></td></th>");
  //.....................................................
  client.println("</table>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
  //-----------------------------------------------------
}

void setPins(){
  pinMode(pin1, OUTPUT);
  digitalWrite(pin1, HIGH);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin2, HIGH);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin3, HIGH);
  pinMode(pin4, OUTPUT);
  digitalWrite(pin4, HIGH);
  pinMode(pin5, OUTPUT);
  digitalWrite(pin5, HIGH);
  pinMode(pin6, OUTPUT);
  digitalWrite(pin6, HIGH);
  pinMode(pin7, OUTPUT);
  digitalWrite(pin7, HIGH);
  pinMode(pin8, OUTPUT);
  digitalWrite(pin8, HIGH);
}


