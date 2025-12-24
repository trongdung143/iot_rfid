#pragma once
#include "setup.h"
extern const String ssid;
extern const String password;
void wifi_init();
String send_image_to_server(camera_fb_t *fb, String rfid_id);
void test_api(String rfid_id);