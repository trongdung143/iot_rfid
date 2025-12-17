#include "camera.h"
#include "servo.h"
#include "connection.h"
#include "rfid.h"
#include "display.h"

bool opened = false;
unsigned long time_open = 0;
String uid = "";
void setup()
{
  Serial.begin(115200);
  SPI.begin(OLED_CLK, 20, OLED_MOSI);
  wifi_init();
  display_init();
  rfid_init();
  servo_init();

  show_text("Ready");
  delay(3000);
}

void loop()
{
  uid = rfid_get_uid();
  if (uid != "" && !opened)
  {
    show_text(uid);
    opened = true;
    time_open = millis();
    camera_fb_t *fb = capture_image();
    esp_camera_fb_return(fb);
    // send_image_to_server(fb);
    open_gate();
  }

  if (opened && millis() - time_open >= 3000L)
  {
    show_text("Close");
    opened = false;
    close_gate();
  }
  delay(20);
}
