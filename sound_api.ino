#include <WiFi.h>
#include <HTTPClient.h>
#include "credentials.h"

const char ssid[] = WIFI_SSID;
const char password[] = WIFI_PASSWD;

const String message = "インターフォンが鳴ったよ";

WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ;

  WiFi.begin(ssid, password);
  Serial.print("WiFi connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }

  Serial.println(" connected");

  server.begin();

  Serial.print("HTTP Server: http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()
{
  HTTPClient http;
  http.begin(WEBHOOK_URL);
  http.addHeader("Content-Type", "application/json");
  String requestBody = "{\"content\": \"" + message + "\"}";
  http.POST(requestBody);
  http.end();
  delay(10000);

  //  インターフォン音検知コード
  //    long sum = 0;
  //    for(int i=0; i<100; i++)
  //    {
  //        sum += analogRead(A0);
  //    }
  //
  //    sum = sum/100;
  //
  //    Serial.println(sum);
  //
  //    delay(10);
}
