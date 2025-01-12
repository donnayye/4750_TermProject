
#include "BluetoothSerial.h"
#include "DHT.h"
#define DHTPIN 15
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
#define RX2 16
#define TX2 17

String readChar;
String BTreadChar;

void setup() {
  
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RX2, TX2);        //Initialize UART connection
  // put your setup code here, to run once:
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println(F("DHT11 TEST"));
  dht.begin();
}

void loop() {
  // DHT11 Humidifier mod
   float h = dht.readHumidity();
  float t = dht.readTemperature(true);
  if(isnan(h) || isnan(t)){
    Serial.println(F("Failed to read from DHT sensor"));
    return;
  }
  Serial.print("H ");
  Serial.print(h);
  Serial.print("\n");
  Serial.print("T ");
  Serial.print(t);
  Serial.print("\n");
  delay(2001);
  // ESP32 Code part
    if ((Serial2.available() > 1) && (SerialBT.available() == 0))
    {
      readChar = Serial2.readString(); 
      SerialBT.print(readChar);
      Serial.print(readChar);
    }
    else if (SerialBT.available() > 1) {
      BTreadChar = SerialBT.readString();
      Serial.print(BTreadChar);
    }
    delay(1000);
    
}
