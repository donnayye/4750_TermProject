#define RX2 16
#define TX2 17

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

String readChar;
String BTreadChar;

void setup() {
  SerialBT.begin("ESP32test");                        //Bluetooth device name
  Serial.begin(115200);                               //Initialize serial monitor
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial2.begin(115200, SERIAL_8N1, RX2, TX2);        //Initialize UART connection
}

void loop() {
    if ((Serial2.available() > 1) && (SerialBT.available() == 0))     //If UART data is being received and BT
    {                                                                 //data from phone isn't being received
      readChar = Serial2.readString();                                //Print UART data to serial monitor, and send over BT
      SerialBT.print(readChar);
      Serial.print(readChar);
    }
    else if (SerialBT.available() > 1) {                              //else if BT data is being received, print to
      BTreadChar = SerialBT.readString();                             //serial monitor
      Serial.print(BTreadChar);
    }
    delay(1000);
}
