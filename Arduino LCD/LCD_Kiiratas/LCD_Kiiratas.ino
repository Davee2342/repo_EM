#include <Wire.h> //könyvtár hozzáadása
#include <LiquidCrystal_I2C.h> //könyvtár hozzáadása

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Arduino LCD hez való csatlakoztatása

void setup() // azt jelzi, hogy a benne lévő kódot egyszer futtatja le a program indulásakor
{
  
lcd.begin(16,2);// 16 oszlop és 2 sor lcd kijelző meghatározása
lcd.backlight();// Lcd háttér fény bekapcsolása
//lcd.backlight();// Lcd háttér fény kikapcsolása
}

void loop() // folyamatos végrehajtást teszi lehetővé
{

lcd.setCursor(0,0); // Az első sor, első oszlop pozíció meghatározása
lcd.print(" ABCDEFGHIJKLM"); // függvény szöveget vagy adatot jelenít meg 
delay(4000); // 4mp várakozás 
lcd.setCursor(0,1);  // A második sor, első oszlop pozíció meghatározása
lcd.print(" NOPQRSTUVWXYZ"); // függvény szöveget vagy adatot jelenít meg
delay(2000); // 2mp várakozás

lcd.clear(); // lcd kijelző törlése

for (int i = 1; i <= 9; i++) { // 1-9 ig elszámol
    lcd.clear(); //lcd kijelző törlése
    lcd.setCursor(0, 0); // Az első sor, első oszlop pozíció meghatározása
    lcd.print("  "); // függvény szöveget vagy adatot jelenít meg
    lcd.print(i); // függvény szöveget vagy adatot jelenít meg
    delay(1000); // 1mp várakozás
}
for (int i = 1; i <= 100; i++) { // 1-100 ig elszámol
    lcd.clear(); // lcd kijelző törlése
    lcd.setCursor(0, 0); // Az első sor, első oszlop pozíció meghatározása
    char buffer[4]; // egy 4 elemű karaktertömböt hoz létre. Ez a tömb 4 karakter tárolására alkalmas
    sprintf(buffer, "%3d", i);// Ha az i értéke kevesebb mint 3 karakter, akkor szóközökkel tölti ki a helyet balról.
    lcd.print(buffer); // függvény szöveget vagy adatot jelenít meg
    delay(1000); //1mp várakozás
  }
  for (int i = 100; i >= 1; i--) { // 100- 1 ig elszámol
    lcd.clear(); // lcd kijelző törlése
    lcd.setCursor(0, 0); // Az első sor, első oszlop pozíció meghatározása
    char buffer[4]; // egy 4 elemű karaktertömböt hoz létre
    sprintf(buffer, "%3d", i); // Ha az i értéke kevesebb mint 3 karakter, akkor szóközökkel tölti ki a helyet balról.
    lcd.print(buffer); // függvény szöveget vagy adatot jelenít meg
    delay(1000); //1mp várakozás
  }
}
