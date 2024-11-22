#include <ThingerESP32.h>
#include "DHT.h"

#define SSID "Wokwi-GUEST"
#define SSID_PASSWORD ""

#define USER "serbato"
#define DEVICE_ID "gs"
#define DEVICE_PASS "40028922"

#define LED_RED 25
#define ANALOG_PIN1 34
#define ANALOG_PIN2 35
#define DHT1_PIN 26
#define DHT2_PIN 27
#define DHT_TYPE DHT22

ThingerESP32 thing(USER, DEVICE_ID, DEVICE_PASS);
DHT dht1(DHT1_PIN, DHT_TYPE);
DHT dht2(DHT2_PIN, DHT_TYPE); 

float readVoltage(int analogPin) {
  int rawValue = analogRead(analogPin);
  return (rawValue / 4095.0) * 3.3;
}


float calculateAmperage(float voltage) {
  return voltage * 2.5;
}

float calculatePower(float voltage, float amperage) {
  return voltage * amperage;
}

float calculateResistance(float voltage, float amperage) {
  if (amperage == 0) return 0;
  return voltage / amperage;
}

float calculateEnergy(float power, float timeHours) {
  return power * timeHours;
}

void setup() {
  pinMode(LED_RED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Inicializando ESP32...");

  dht1.begin();
  dht2.begin();

  thing.add_wifi(SSID, SSID_PASSWORD);

  thing["Sensor1_Temperature"] >> [](pson& out) {
    out = dht1.readTemperature();
  };
  thing["Sensor1_Voltage"] >> [](pson& out) {
    out = readVoltage(ANALOG_PIN1);
  };
  thing["Sensor1_Amperage"] >> [](pson& out) {
    float voltage = readVoltage(ANALOG_PIN1);
    out = calculateAmperage(voltage);
  };
  thing["Sensor1_Power"] >> [](pson& out) {
    float voltage = readVoltage(ANALOG_PIN1);
    float amperage = calculateAmperage(voltage);
    out = calculatePower(voltage, amperage);
  };
  thing["Sensor1_Resistance"] >> [](pson& out) {
    float voltage = readVoltage(ANALOG_PIN1);
    float amperage = calculateAmperage(voltage);
    out = calculateResistance(voltage, amperage);
  };
  thing["Sensor1_Energy"] >> [](pson& out) {
    float voltage = readVoltage(ANALOG_PIN1);
    float amperage = calculateAmperage(voltage);
    float power = calculatePower(voltage, amperage);
    out = calculateEnergy(power, 0.002);
  };

  thing["Sensor2_Temperature"] >> [](pson& out) {
    out = dht2.readTemperature();
  };
  thing["Sensor2_Voltage"] >> [](pson& out) {
    out = readVoltage(ANALOG_PIN2);
  };
  thing["Sensor2_Amperage"] >> [](pson& out) {
    float voltage = readVoltage(ANALOG_PIN2);
    out = calculateAmperage(voltage);
  };
  thing["Sensor2_Power"] >> [](pson& out) {
    float voltage = readVoltage(ANALOG_PIN2);
    float amperage = calculateAmperage(voltage);
    out = calculatePower(voltage, amperage);
  };
  thing["Sensor2_Resistance"] >> [](pson& out) {
    float voltage = readVoltage(ANALOG_PIN2);
    float amperage = calculateAmperage(voltage);
    out = calculateResistance(voltage, amperage);
  };
  thing["Sensor2_Energy"] >> [](pson& out) {
    float voltage = readVoltage(ANALOG_PIN2);
    float amperage = calculateAmperage(voltage);
    float power = calculatePower(voltage, amperage);
    out = calculateEnergy(power, 0.002);
  };

  Serial.println("Configuração concluída!");
}

void loop() {
  thing.handle();

  float temp1 = dht1.readTemperature();
  float temp2 = dht2.readTemperature();
  float sensor1Volt = readVoltage(ANALOG_PIN1);
  float sensor1Amper = calculateAmperage(sensor1Volt);
  float sensor1Power = calculatePower(sensor1Volt, sensor1Amper);
  float sensor1Resistance = calculateResistance(sensor1Volt, sensor1Amper);
  float sensor1Energy = calculateEnergy(sensor1Power, 0.002);

  float sensor2Volt = readVoltage(ANALOG_PIN2);
  float sensor2Amper = calculateAmperage(sensor2Volt);
  float sensor2Power = calculatePower(sensor2Volt, sensor2Amper);
  float sensor2Resistance = calculateResistance(sensor2Volt, sensor2Amper);
  float sensor2Energy = calculateEnergy(sensor2Power, 0.002);

  Serial.println("=== Dados dos Sensores ===");

  Serial.print("Sensor 1 - Temperatura: ");
  Serial.print(temp1);
  Serial.println(" °C");

  Serial.print("Sensor 1 - Voltagem: ");
  Serial.print(sensor1Volt);
  Serial.println(" V");

  Serial.print("Sensor 1 - Amperagem: ");
  Serial.print(sensor1Amper);
  Serial.println(" A");

  Serial.print("Sensor 1 - Potência: ");
  Serial.print(sensor1Power);
  Serial.println(" W");

  Serial.print("Sensor 1 - Resistência: ");
  Serial.print(sensor1Resistance);
  Serial.println(" Ω");

  Serial.print("Sensor 1 - Energia: ");
  Serial.print(sensor1Energy);
  Serial.println(" Wh");

  Serial.print("Sensor 2 - Temperatura: ");
  Serial.print(temp2);
  Serial.println(" °C");

  Serial.print("Sensor 2 - Voltagem: ");
  Serial.print(sensor2Volt);
  Serial.println(" V");

  Serial.print("Sensor 2 - Amperagem: ");
  Serial.print(sensor2Amper);
  Serial.println(" A");

  Serial.print("Sensor 2 - Potência: ");
  Serial.print(sensor2Power);
  Serial.println(" W");

  Serial.print("Sensor 2 - Resistência: ");
  Serial.print(sensor2Resistance);
  Serial.println(" Ω");

  Serial.print("Sensor 2 - Energia: ");
  Serial.print(sensor2Energy);
  Serial.println(" Wh");

  Serial.println("==========================");

  delay(2000);
}
