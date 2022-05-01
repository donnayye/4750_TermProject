 #include "DHT.h"                         //UPLOADED TO ARDUINO
 #define DHTPIN 2
 #define DHTTYPE DHT11
 DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT11 TEST"));
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();           //Read humidity (percentage), store in h
  float t = dht.readTemperature(true);    //Read temperature (Fahrenheit), store in t
  if(isnan(h) || isnan(t)){               //If either values don't represent a decimal, there was a reading error
    Serial.println(F("Failed to read from DHT sensor"));
    return;
  }
  Serial.print("H ");                     //Print humidity and temp over monitor and
  Serial.print(h);                        //send over UART
  Serial.print("\n");
  Serial.print("T ");
  Serial.print(t);
  Serial.print("\n");
  delay(2001);
}
