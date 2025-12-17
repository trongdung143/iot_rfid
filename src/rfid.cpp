#include "rfid.h"
MFRC522 rfid(RFID_SDA, RFID_RST);
void rfid_init()
{

    rfid.PCD_Init();
    delay(50);
}

String rfid_get_uid()
{
    String uid = "";

    if (!rfid.PICC_IsNewCardPresent())
        return "";

    if (!rfid.PICC_ReadCardSerial())
        return "";

    for (byte i = 0; i < rfid.uid.size; i++)
    {
        if (rfid.uid.uidByte[i] < 0x10)
            uid += "0";
        uid += String(rfid.uid.uidByte[i], HEX);
    }

    uid.toUpperCase();

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    return uid;
}

void rfid_stop()
{
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
}
