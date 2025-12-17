#pragma once
#include "setup.h"

extern MFRC522 rfid;

void rfid_init();
String rfid_get_uid();
void rfid_stop();
