#include <WiFi.h>

void setup()
{ 
  
    Serial.begin(115200);
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
