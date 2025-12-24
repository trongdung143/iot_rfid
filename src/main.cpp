#include "camera.h"
#include "servo.h"
#include "connection.h"
#include "rfid.h"
#include "display.h"

bool opened = false;
unsigned long time_open = 0;
String rfid_id = "";
void setup()
{
  Serial.begin(115200);
  SPI.begin(OLED_CLK, 20, OLED_MOSI);
  display_init();
  rfid_init();
  servo_init();
  wifi_init();
  camera_init();

  // show_text("Ready");
  delay(3000);
}

void loop()
{
  rfid_id = rfid_get_uid();
  if (rfid_id != "" && !opened)
  {

    opened = true;
    time_open = millis();
    camera_fb_t *fb = capture_image();
    String suggested_slot = send_image_to_server(fb, rfid_id);
    show_text(suggested_slot);
    open_gate();
    delay(5000);
  }

  if (opened)
  {
    show_text("Close");
    opened = false;
    close_gate();
  }
  delay(20);
}
