//including all libraries
#include <Wire.h>
#include <Adafruit_PN532.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h> 

//  WiFi connection name and password
const char* ssid = "Redmi Note 9 Pro";
const char* password = "1234567890";

// defining connections
#define SDA_PIN 21
#define SCL_PIN 22
#define PN532_IRQ   4
#define PN532_RESET 5
#define led 18
#define buzzer 14

//setting up pn532 & lcd display
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);
LiquidCrystal_I2C lcd(0x27, 16, 2);  
 
String uidString = "";
const char* SHEET_URL = "https://script.google.com/macros/s/AKfycbzkhfbUcEEdq3NgN1PgROP6uWu5SsbgDF8DP0DH47nk-hU0uQMl7xEQF9G86fdAt99y/exec";

void setup() {
  Serial.begin(115200);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);

  Wire.begin(SDA_PIN, SCL_PIN);

  // LCD start-up
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smart Attendence");
  lcd.setCursor(0,1);
  lcd.print("System");
  digitalWrite(led,HIGH);
  delay(2100);

  // PN532 check
  nfc.begin();
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    lcd.clear();
    lcd.print("Check PN532!");
    tone(buzzer,1000);
    while(1);
  }

  nfc.SAMConfig();

  lcd.clear();
  lcd.print("Tap ID Card...");

  // WiFi connect
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  boolean success;
  uint8_t uid[7];
  uint8_t uidLength;

  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {

    // Convert UID
    uidString = "";
    for (uint8_t i = 0; i < uidLength; i++) {
      if (uid[i] < 0x10) uidString += "0";
      uidString += String(uid[i], HEX);
    }
    uidString.toUpperCase();

    // Display success
    lcd.clear();
    lcd.setCursor(0,0);
    tone(buzzer,1000);
    digitalWrite(led,HIGH);
    lcd.print("Recorded");
    lcd.setCursor(0,1);
    lcd.print("Status: Present");
    delay(150);

    noTone(buzzer);
    digitalWrite(led,LOW);

    // Send to Google Sheets
    String url = String(SHEET_URL) + "?uid=" + uidString;

    if(WiFi.status() == WL_CONNECTED){
      WiFiClientSecure client;
      client.setInsecure();

      HTTPClient https;
      https.begin(client, url);
      https.GET();
      https.end();
    }

    // ✅ FIXED LINE
    delay(1500);   // wait before next scan

    lcd.clear();
    lcd.setCursor(0,0);

    tone(buzzer,1000);
    digitalWrite(led,HIGH);
    delay(125);

    noTone(buzzer);
    digitalWrite(led,LOW);

    lcd.print("Next ID Pls...");
  }
}
