 #include "DHT.h"
 #define DHTPIN 2
 #define DHTTYPE DHT11
 DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT11 TEST"));
  dht.begin();
}

void loop() {
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
}
