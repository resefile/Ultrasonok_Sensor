#include <Wire.h> // I2C iletişim kütüphanesi
#include <LiquidCrystal_I2C.h> // LCD kütüphanesi

LiquidCrystal_I2C lcd(0x27, 16, 2); // 16x2 LCD için I2C adresi (0x27)

// Birinci sensör pinleri
int trigPin1 = A0;
int echoPin1 = A1;

// İkinci sensör pinleri
int trigPin2 = A2;
int echoPin2 = A3;

long distance1; // Birinci sensör mesafesi
long duration1;

long distance2; // İkinci sensör mesafesi
long duration2;

void setup() {
  lcd.begin(16, 2); // LCD ekranı başlat
  lcd.backlight(); // LCD arka ışığını aç

  // Birinci sensör pin modları
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
  // İkinci sensör pin modları
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("MESAFE OLCUMU");
  lcd.setCursor(0, 1);
  lcd.print(" ELIF ESER ");
  delay(2000);
}

void loop() {
  // Birinci sensör ölçüm
  measureDistance(trigPin1, echoPin1, distance1);
  
  // İkinci sensör ölçüm
  measureDistance(trigPin2, echoPin2, distance2);

  lcd.clear();
  
  // Birinci sensör mesafesi
  lcd.setCursor(0, 0);
  lcd.print("D1:");
  lcd.print(distance1);
  lcd.print("cm ");
  
  // İkinci sensör mesafesi
  lcd.print("D2:");
  lcd.print(distance2);
  lcd.print("cm");

  delay(2000); // Mesafeyi göstermek için bekle
}

// Mesafe ölçüm fonksiyonu
void measureDistance(int trigPin, int echoPin, long &distance) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}