#include "camera.h"
#include "servo.h"
#include "connection.h"
#include "rfid.h"
#include "display.h"

String rfid_id = "";
bool gate_in = false;
void setup()
{
  Serial.begin(115200);
  SPI.begin(OLED_CLK, 20, OLED_MOSI);
  display_init();
  rfid_init();
  servo_init();
  wifi_init();
  camera_init();
  delay(3000);
}

void loop()
{
  rfid_id = rfid_get_uid();
  if (rfid_id != "")
  {
    camera_fb_t *fb = capture_image();
    if (gate_in)
    {
      String suggested_slot = in_parking(fb, rfid_id);
      if (suggested_slot != "NOT")
      {
        show_text(suggested_slot);
        open_gate();
        delay(3000);
        show_text("Close");
        close_gate();
      }
    }
    else
    {
      String total_money = out_parking(fb, rfid_id);
      if (total_money != "NOT")
      {
        show_text(total_money);
        open_gate();
        delay(3000);
        show_text("Close");
        close_gate();
      }
    }
  }
  delay(20);
}
