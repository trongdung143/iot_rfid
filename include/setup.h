#include "esp_camera.h"
#include <WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
#include <ESP32Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <esp_heap_caps.h>
#include <Arduino.h>
#include <HTTPClient.h>

// display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_MOSI 21
#define OLED_CLK 19
#define OLED_DC 42
#define OLED_CS 41
#define OLED_RST 39

// rfid
#define RFID_SDA 38
#define RFID_RST 47
#define RFID_MOSI 21
#define RFID_CLK 19
#define RFID_MISO 20

// servo
#define SERVO_PIN 40
#define OPEN_ANGLE 70
#define CLOSE_ANGLE 0
#define OPEN_TIME 3000

// camera
#define PWDN_GPIO_NUM -1
#define RESET_GPIO_NUM -1
#define XCLK_GPIO_NUM 15
#define SIOD_GPIO_NUM 4
#define SIOC_GPIO_NUM 5

#define Y2_GPIO_NUM 11
#define Y3_GPIO_NUM 9
#define Y4_GPIO_NUM 8
#define Y5_GPIO_NUM 10
#define Y6_GPIO_NUM 12
#define Y7_GPIO_NUM 18
#define Y8_GPIO_NUM 17
#define Y9_GPIO_NUM 16

#define VSYNC_GPIO_NUM 6
#define HREF_GPIO_NUM 7
#define PCLK_GPIO_NUM 13
