#include "connection.h"

const String ssid = "Luu";
const String password = "matkhaula@123@";

void wifi_init()
{
    WiFi.begin(ssid, password);
    WiFi.setSleep(false);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
}

void send_image_to_server(camera_fb_t *fb)
{
    if (!fb)
        return;

    HTTPClient http;
    http.begin("http://<IP_SERVER>:8000/upload");
    http.addHeader("Content-Type", "image/jpeg");

    int httpCode = http.POST(fb->buf, fb->len);
    Serial.println(httpCode);

    http.end();
    esp_camera_fb_return(fb);
}
