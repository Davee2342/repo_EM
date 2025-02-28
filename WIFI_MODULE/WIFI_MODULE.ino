#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "LonyayC";
const char* password = "L1o6ny5a2y";

ESP8266WebServer server(80);

void handleRoot(String mas) {
  String ipAddress = WiFi.localIP().toString();
  String html = "<html><body><h1>Dolgozzatok</h1><p>" + mas + "</p></body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to WiFi...");
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(1000);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot(" "));
    server.begin();
    Serial.println("HTTP server started");
  } else {
    Serial.println("\nFailed to connect to WiFi");
  }
}

void loop() {
  server.handleClient();
  String q="akarmi";
  for (int a=0;a<1000;a++){
    q=q+" valami ";
    handleRoot(q);
    delay(2000);
  }
}
