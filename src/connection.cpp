#include "connection.h"
#include "display.h"
#include <ArduinoJson.h>

const String ssid = "Luu";
const String password = "matkhaula@123@";

void wifi_init()
{
    WiFi.begin(ssid, password);
    WiFi.setSleep(false);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        show_text("Connecting");
    }
    show_text(WiFi.localIP().toString());
}

void test_api(String rfid_id)
{
    HTTPClient http;
    String url = "http://192.168.1.100:8080/";
    http.begin(url);
    int httpCode = http.GET();
    show_text("HTTP code: ");
    show_text(String(httpCode));
    http.end();
}

String send_image_to_server(camera_fb_t *fb, String rfid_id)
{
    if (!fb)
        return "ERROR1";

    if (fb->format != PIXFORMAT_JPEG)
    {
        esp_camera_fb_return(fb);
        return "ERROR2";
    }

    WiFiClient client;
    HTTPClient http;

    String url = "http://192.168.1.100:8080/api/v1/esp32/in-upload";
    url += "?rfid_id=" + rfid_id;

    http.begin(client, url);
    http.addHeader("Content-Type", "image/jpeg");
    http.setTimeout(15000);

    int httpCode = http.POST(fb->buf, fb->len);

    String suggested_slot = "NOT";

    if (httpCode == HTTP_CODE_OK)
    {
        String payload = http.getString();
        JsonDocument doc;
        if (!deserializeJson(doc, payload))
        {
            suggested_slot = doc["suggested_slot"] | "";
        }
    }

    http.end();
    esp_camera_fb_return(fb);
    return suggested_slot;
}
