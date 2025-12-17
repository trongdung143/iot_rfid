#pragma once
#include "setup.h"
extern const String ssid;
extern const String password;
void wifi_init();
void send_image_to_server(camera_fb_t *fb);