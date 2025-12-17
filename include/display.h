#pragma once
#include "setup.h"

extern Adafruit_SSD1306 display;

void show_text(const String &text);
void display_init();