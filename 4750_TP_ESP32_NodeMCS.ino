#define RX2 16
#define TX2 17

#include "BluetoothSerial.h"            // Bing Bong

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

String readChar;
String BTreadChar;

void setup() {
  SerialBT.begin("ESP32test"); //Bluetooth device name
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial2.begin(115200, SERIAL_8N1, RX2, TX2);
}

void loop() {
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
