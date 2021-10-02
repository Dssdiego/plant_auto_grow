/*
 * Firmware para controlar um display LCD 16x2 by tecdicas
 * Biblioteca/Library : LiquidCrystal
 * 27/10/2017
 */
#include <LiquidCrystal.h> // Adiciona a biblioteca "LiquidCrystal" ao projeto

LiquidCrystal lcd(12, 13, 7, 6, 5, 4); // Pinagem do LCD

// Pins
int soilPin = A5;

// Definitions
int backlight = 100;
int soilMoisture = 0;

byte smiley[8] = {
  B11111,
  B10001,
  B00001,
  B00001,
  B10001,
  B01111,
  B00001,
  B11111,
};

byte n4[8] = {
  B00000,
  B00000,
  B01010,
  B01010,
  B01110,
  B00010,
  B00010,
  B00000,
};

byte n5[8] = {
  B00000,
  B00000,
  B01110,
  B01000,
  B01110,
  B00010,
  B01110,
  B00000,
};

byte degree[8] = {
  B00000,
  B00000,
  B00010,
  B00101,
  B00010,
  B00000,
  B00000,
  B00000,
};

byte c[8] = {
  B00000,
  B00000,
  B00110,
  B01000,
  B01000,
  B01000,
  B00110,
  B00000,
};

byte temp[8] = {
  B00000,
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110,
};

/*
 * Setup
 */
void setup()
{
  lcd.createChar(0, smiley);
  lcd.createChar(1, n4);
  lcd.createChar(2, n5);
  lcd.createChar(3, degree);
  lcd.createChar(4, c);
  lcd.createChar(5, temp);
  lcd.begin(16, 2); // Inicia o lcd de 16x2

  Serial.begin(9600);
}

// TODO: Controlar backlight conforme hora do dia ou luminosidade
// TODO: Separar em múltiplos arquivos

/*
 * Loop
 */
void loop()
{
  // Backlight do LCD
  analogWrite(3,backlight);
  
  // Temperatura
  lcd.clear();              
  lcd.setCursor(0, 0);      
  lcd.write("Maker Friday");
  lcd.write(" ");
  lcd.write(byte(0));
//  lcd.print("Temp. Ar 45 ");
//  lcd.print((char) 223);
//  lcd.print("C"); 

//  if (backlight <= 100)
//  {
//    backlight += 25;
//  }

  lcd.setCursor(0,1);
  lcd.print("45 C");
  lcd.print(" ");
  lcd.write(byte(5));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));

  soilMoisture = analogRead(soilPin);
  
//  lcd.clear(); 
//  lcd.setCursor(3, 0);
//  lcd.print("Ola Mundo!");  
  delay(3000);

  // Solo
  
  Serial.println(soilMoisture);
}
