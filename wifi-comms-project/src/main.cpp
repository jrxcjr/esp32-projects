#include <Arduino.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


//Definition of the GPIO pins that are used to send data to the lcd display
#define SDA 13
#define SCL 14

const char* ssid = "EVOLNET_102_2.4G";
const char* password = "evolnet_jose_102";

//initializing the lib with io pins for the LCD display
LiquidCrystal_I2C lcd (0x3F, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("hello World!");

  //This call for the wire lib, allows the esp32 to establish connection with the pins of the lcd that receives data
  Wire.begin(SDA,SCL);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);

  //init of wifi connection
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to Wifi...");
  }
  Serial.println("Connected to the Wifi network");
}

void loop() {

  //prints the local IP in the lcd display
  lcd.setCursor(0,0);
  lcd.print("WifiNetwork:");
  lcd.setCursor(0,1);
  lcd.print(WiFi.localIP());
  delay(1000);
}