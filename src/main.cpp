#include <Arduino.h>
#include <ArduinoJson.h>

String myJsonString = "{\"ssid\":\"mySSID\",\"password\":\"qwerty\"}";

void serializeMyJson(String ssid, String pass)
{
  String myJson;
  StaticJsonDocument<200> json;

  json["ssid"] = ssid;
  json["password"] = pass;

  serializeJson(json, myJson);
  Serial.println(myJson);
}

void deserializeMyJson(String jsonString)
{
  StaticJsonDocument<200> json;
  DeserializationError errorJson = deserializeJson(json, jsonString);
  if (errorJson)
  {
    Serial.println("Deserialization Failed");
  }
  else
  {
    String ssid = json["ssid"];
    String pass = json["password"];

    Serial.println("SSID: " + ssid);
    Serial.println("Password: " + pass);
  }
}

// JSON Files
void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println();

  serializeMyJson("mySSID", "qwerty");
  // deserializeMyJson(myJsonString);
}

void loop()
{
  // put your main code here, to run repeatedly:
}