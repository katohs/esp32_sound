# インターフォン検知

esp32 + サウンドセンサーモジュールを使用し、自宅のインターフォンが鳴ると、discordに通知を飛ばすプロジェクト。

構成

- HiLetgo ESP32 ESP-32S
- HiLetgo サウンドセンサーモジュール

注意事項

ssid, password, webhookurlはcredentials.hから、値をincludeしています。

このプロジェクトを使用したい場合は、ご自身でcredentials.hファイルを作成してください

例

```c
#define WIFI_SSID "ssid"
#define WIFI_PASSWD "password"
#define WEBHOOK_URL "URL"
```