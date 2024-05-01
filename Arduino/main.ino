// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11
#define soil_moisture_pin 32

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Sensor prueba"));

  dht.begin();
}

void loop() {
  delay(60000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Fallo de conexion con el DHT"));
    return;
  }
  
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humedad: "));
  Serial.print(h);
  Serial.print(F("%  Temperatura: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(F("°F  Indice de Calor: "));
  Serial.print(hic);
  Serial.print(F(" Humedad del suelo: "));
  Serial.print(analogRead(soil_moisture_pin));
  Serial.println("---");

  //Serial.print(F("°C "));
  //Serial.print(hif);
  //Serial.println(F("°F"));
}