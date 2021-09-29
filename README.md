# インターフォン検知

構成

- HiLetgo ESP32 ESP-32S
- HiLetgo サウンドセンサーモジュール

注意事項

ssid, password, webhookurlはcredentials.hから、includeしています。

このプロジェクトを使用したい場合は、ご自身でcredentials.hファイルを作成してください

例

```c:credentials.h
#define WIFI_SSID "ssid"
#define WIFI_PASSWD "password"
#define WEBHOOK_URL "URL"
```
