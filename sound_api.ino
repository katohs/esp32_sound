#include <WiFi.h>

  // TODO 環境変数の使い方を調べる
  const char SSID[] = "ssid"
  const char PASSWORD[] = "wifi paddword"
  WiFiServer server(80);

void setup()
{ 
  Serial.begin(115200);
  while (!Serial);

  WiFi.begin(SSID, PASSWORD);
  Serial.print("WiFi connecting");

  while (WiFi.status() != WL_CONNECTED) {
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
    long sum = 0;
    for(int i=0; i<100; i++)
    {
        sum += analogRead(A0);
    }
 
    sum = sum/100;
 
    Serial.println(sum);
 
    delay(10);
}
