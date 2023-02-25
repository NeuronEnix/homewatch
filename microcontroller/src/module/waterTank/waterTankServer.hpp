#include <Arduino.h>
#include <ArduinoJson.hpp>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include "blueprint-waterTank.hpp"

using waterTankModule::I_WaterTankContainer;
using waterTankModule::WaterTankServer;

class waterTankModule::WaterTankServer
{

private:
  ESP8266WebServer *server;
  I_WaterTankContainer *container;
  WiFiManager wifiManager;

public:
  WaterTankServer(I_WaterTankContainer *container)
  {
    this->container = container;
    this->server = new ESP8266WebServer(80);
  }
  ~WaterTankServer()
  {
    delete container;
    delete server;
  }

  void setup();
  void loop();
  void handleWaterTankDetail();
};

void WaterTankServer::handleWaterTankDetail()
{

  auto contentLiter = this->container->getContentLiter();
  auto contentPercent = this->container->getContentPercent();

  ArduinoJson::StaticJsonDocument<128> doc;
  doc["contentLiter"] = contentLiter;
  doc["contentPercent"] = contentPercent;

  String resBody;
  serializeJson(doc, resBody);

  server->send(200, "application/json", resBody);
}

void WaterTankServer::setup()
{

  IPAddress staticIP;
  staticIP.fromString(WIFI_STATIC_IP);
  IPAddress gateway;
  gateway.fromString(WIFI_GATEWAY);
  IPAddress subnetMask;
  subnetMask.fromString(WIFI_SUBNET_MASK);
  wifiManager.setSTAStaticIPConfig(staticIP, gateway, subnetMask);
  wifiManager.autoConnect("WaterTankAP");

  server->on("/waterTankDetail", HTTP_GET, [this]()
             { handleWaterTankDetail(); });
  server->begin();
}

void WaterTankServer::loop()
{
  this->server->handleClient();
}
