#include <DHT.h>

// ---------- Pin Connections ----------
#define GAS_SENSOR 34
#define DHT_PIN 4
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

// ---------- Gas Threshold ----------
int gasThreshold = 1800;

void setup()
{
  Serial.begin(115200);

  dht.begin();

  Serial.println();
  Serial.println("=================================");
  Serial.println(" SMART FOOD FRESHNESS DETECTOR");
  Serial.println("=================================");
  Serial.println("System Started...");
  Serial.println();
}

void loop()
{
  // ---------- Read Gas Sensor ----------
  int gasValue = analogRead(GAS_SENSOR);

  // ---------- Read DHT11 ----------
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check DHT11
  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("ERROR: DHT11 sensor not detected!");
    delay(2000);
    return;
  }

  // ---------- Display Sensor Values ----------
  Serial.println("---------------------------------");

  Serial.print("Gas Value       : ");
  Serial.println(gasValue);

  Serial.print("Temperature     : ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity        : ");
  Serial.print(humidity);
  Serial.println(" %");

  // ---------- Gas Detection ----------
  bool highGas = gasValue > gasThreshold;

  if (highGas)
  {
    Serial.println("⚠ WARNING: HIGH SPOILAGE GAS!");
  }
  else
  {
    Serial.println("Gas Condition   : NORMAL");
  }

  // ---------- Storage Condition ----------
  bool poorStorage = false;

  if (temperature > 30 || humidity > 75)
  {
    poorStorage = true;
    Serial.println("⚠ WARNING: POOR STORAGE CONDITION!");
  }
  else
  {
    Serial.println("Storage         : GOOD");
  }

  // ---------- Food Status ----------
  String foodStatus;

  if (highGas)
  {
    foodStatus = "SPOILED";
  }
  else if (poorStorage)
  {
    foodStatus = "EAT SOON";
  }
  else
  {
    foodStatus = "FRESH";
  }

  Serial.print("Food Status     : ");
  Serial.println(foodStatus);

  // ---------- Shelf Life ----------
  int shelfLife;

  if (highGas)
  {
    shelfLife = 0;
  }
  else if (temperature > 30 || humidity > 75)
  {
    shelfLife = 2;
  }
  else if (temperature > 27 || humidity > 65)
  {
    shelfLife = 3;
  }
  else
  {
    shelfLife = 5;
  }

  Serial.print("Estimated Shelf Life : ");
  Serial.print(shelfLife);
  Serial.println(" days");

  // ---------- Recipe Suggestion ----------
  Serial.print("Suggestion     : ");

  if (foodStatus == "FRESH")
  {
    Serial.println("Food can be stored normally.");
  }
  else if (foodStatus == "EAT SOON")
  {
    Serial.println("Cook the food soon.");
  }
  else
  {
    Serial.println("DO NOT CONSUME.");
  }

  Serial.println("---------------------------------");

  delay(5000);
}
