#include <WiFi.h>
#include <HTTPClient.h>
// 秘匿情報をinclude
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
  
  long sound = 0;
  for (int i = 0; i < 100; i++)
  {
    sound += analogRead(A0);
  }
  const long AVG = sound / 100;

  if (AVG > 1500)
  {
    const String requestBody = "{\"content\": \"" + message + "\"}";
    http.POST(requestBody);
    http.end();
  }

  Serial.println(AVG);

  delay(1000);
}
