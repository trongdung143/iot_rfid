#include "display.h"
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RST, OLED_CS, 8000000UL);
void show_text(const String &text)
{
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 25);
    display.println(text);
    display.display();
}

void display_init()
{
    display.begin(SSD1306_SWITCHCAPVCC);
}
