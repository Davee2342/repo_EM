#include <Servo.h> // A Servo könyvtár beillesztése, amely lehetővé teszi a szervomotor vezérlését

Servo myservo; // Egy Servo objektum létrehozása

void setup() {
  Serial.begin(9600); // Soros kommunikáció inicializálása 9600 bit/s sebességgel
  myservo.attach(9); // A szervomotor csatlakoztatása a 9-es pinhez
}

void loop() {
  int val; // Egy változó létrehozása az érték tárolására
  while (Serial.available() > 0) { // Amíg van elérhető adat a soros porton
    val = Serial.parseInt(); // Az adat beolvasása és egész számként értelmezése
    if (val != 0) { // Ha az érték nem nulla
      if (val > 180) {
        val = 180; // Ha az érték nagyobb, mint 180, akkor állítsa be 180-ra
      }
      Serial.println(val); // Az érték kiírása a soros monitorra
      myservo.write(val); // A szervomotor pozíciójának beállítása az érték alapján
    }
  }
  delay(5); // Rövid késleltetés a ciklus végén
}
