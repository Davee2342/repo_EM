#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
// Replace with your network credentials
const char* ssid = "LonyayC"; //Írd át a te vezetéknélküli hálózatod nevére
const char* password = "L1o6ny5a2y"; //Írd át a te vezetéknélküli hálózatod jelszavára
ESP8266WebServer server(80); // server port 80 (http port)
String page = "";
int LEDPin = 5;
void setup(void){
//A HTML kódja a weblapnak
page = "<h1 style=\"color:green;\">Egyszeru NodeMCU Webszerver</h1>"
      "<p><a href=\"LEDOn\"><button style=\"background-color:green; color:white;\">ON</button></a>&nbsp;"
      "<a href=\"LEDOff\"><button style=\"background-color:red; color:white;\">OFF</button></a></p>";
//make the LED pin output and initially turned off
pinMode(LEDPin, OUTPUT);
digitalWrite(LEDPin, LOW);
delay(1000);
Serial.begin(115200);
WiFi.begin(ssid, password); // WiFi csatlakozás kezdete
Serial.println("");
// Wait for connection
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.print("Csatlakozva a(z) ");
Serial.println(ssid);
Serial.print("IP cim: ");
Serial.println(WiFi.localIP());
server.on("/", [](){
server.send(200, "text/html", page);
});
server.on("/LEDOn", [](){
server.send(200, "text/html", page);
digitalWrite(LEDPin, HIGH);
delay(1000);
});
server.on("/LEDOff", [](){
server.send(200, "text/html", page);
digitalWrite(LEDPin, LOW);
delay(1000);
});
server.begin();
Serial.println("Web server elindult!");
}
void loop(void){
server.handleClient();
}
