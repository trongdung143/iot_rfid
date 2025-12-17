#include "servo.h"
Servo servo;

void servo_init()
{
    servo.attach(SERVO_PIN);
}
void close_gate()
{
    servo.write(CLOSE_ANGLE);
}
void open_gate()
{
    servo.write(OPEN_ANGLE);
}