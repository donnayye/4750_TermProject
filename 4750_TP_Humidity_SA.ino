//Humdifier
#include "DHT.h"

#define DHTPIN 2      // Pin signal connection from the Arduino of DHT11
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE); //Initializing obj and parameter of mod

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(F("DHT11 test!"));

  dht.begin();              // Starting to collect the data from module
}

void loop() {
  //waiting a few seconds b/t measurement
  delay(2000);
 
  // Reading temp/humidity takes about 250 ms
  // Sensor readings may also be up to 2 seconds
  float h = dht.readHumidity();
  // Read temp as Celsius (the default)
  float t = dht.readTemperature();
  // Read temp as fahrenheit 
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again)
  if (isnan(h) || isnan(t) || isnan(f)){
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Displaying prompt on serial monitor
  Serial.print(F(" Humidity: " ));
  Serial.print(h);
  Serial.print(F("%  Temperature:  "));
  Serial.print(t);
  Serial.print(F("C and "));
  Serial.print(F("F \n"));
  Serial.println("Collecting...");
  delay(1000);
}
