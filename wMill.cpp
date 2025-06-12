#include "Arduino.h"
#include "wMill.h"

wMill::wMill(int acs_pin_1, int cny_pin_1) {
    pinMode(this->acs_pin_1, INPUT);
    pinMode(this->cny_pin_1, INPUT);

    this->length = 1;
    vPinArray[0] = acs_pin_1;
    rPinArray[0] = cny_pin_1;
    }


wMill::wMill(int acs_pin_1, int cny_pin_1, 
             int acs_pin_2, int cny_pin_2) {
    pinMode(this->acs_pin_1, INPUT);
    pinMode(this->cny_pin_1, INPUT);
    pinMode(this->acs_pin_2, INPUT);
    pinMode(this->cny_pin_2, INPUT);

    this->length = 2;
    vPinArray[0] = acs_pin_1;
    vPinArray[1] = acs_pin_2;
    rPinArray[0] = cny_pin_1;
    rPinArray[1] = cny_pin_2;
}

wMill::wMill(int acs_pin_1, int cny_pin_1, 
             int acs_pin_2, int cny_pin_2,
             int acs_pin_3, int cny_pin_3) {
    pinMode(this->acs_pin_1, INPUT);
    pinMode(this->cny_pin_1, INPUT);
    pinMode(this->acs_pin_2, INPUT);
    pinMode(this->cny_pin_2, INPUT);
    pinMode(this->acs_pin_3, INPUT);
    pinMode(this->cny_pin_3, INPUT);

    this->length = 3;
    vPinArray[0] = acs_pin_1;
    vPinArray[1] = acs_pin_2;
    vPinArray[2] = acs_pin_3;
    rPinArray[0] = cny_pin_1;
    rPinArray[1] = cny_pin_2;
    rPinArray[2] = cny_pin_3;
}

wMill::wMill(int acs_pin_1, int cny_pin_1, 
             int acs_pin_2, int cny_pin_2,
             int acs_pin_3, int cny_pin_3,
             int acs_pin_4, int cny_pin_4) {
    pinMode(this->acs_pin_1, INPUT);
    pinMode(this->cny_pin_1, INPUT);
    pinMode(this->acs_pin_2, INPUT);
    pinMode(this->cny_pin_2, INPUT);
    pinMode(this->acs_pin_3, INPUT);
    pinMode(this->cny_pin_3, INPUT);
    pinMode(this->acs_pin_4, INPUT);
    pinMode(this->cny_pin_4, INPUT);

    this->length = 4;
    vPinArray[0] = acs_pin_1;
    vPinArray[1] = acs_pin_2;
    vPinArray[2] = acs_pin_3;
    vPinArray[3] = acs_pin_4;
    rPinArray[0] = cny_pin_1;
    rPinArray[1] = cny_pin_2;
    rPinArray[2] = cny_pin_3;
    rPinArray[3] = cny_pin_4;
}

wMill::wMill(int acs_pin_1, int cny_pin_1, 
             int acs_pin_2, int cny_pin_2,
             int acs_pin_3, int cny_pin_3,
             int acs_pin_4, int cny_pin_4,
             int acs_pin_5, int cny_pin_5) {
    pinMode(this->acs_pin_1, INPUT);
    pinMode(this->cny_pin_1, INPUT);
    pinMode(this->acs_pin_2, INPUT);
    pinMode(this->cny_pin_2, INPUT);
    pinMode(this->acs_pin_3, INPUT);
    pinMode(this->cny_pin_3, INPUT);
    pinMode(this->acs_pin_4, INPUT);
    pinMode(this->cny_pin_4, INPUT);
    pinMode(this->acs_pin_5, INPUT);
    pinMode(this->cny_pin_5, INPUT);

    this->length = 5;
    vPinArray[0] = acs_pin_1;
    vPinArray[1] = acs_pin_2;
    vPinArray[2] = acs_pin_3;
    vPinArray[3] = acs_pin_4;
    vPinArray[4] = acs_pin_5;
    rPinArray[0] = cny_pin_1;
    rPinArray[1] = cny_pin_2;
    rPinArray[2] = cny_pin_3;
    rPinArray[3] = cny_pin_4;
    rPinArray[4] = cny_pin_5;
}
float* wMill::getVoltage() {
    for (int i = 0; i < length; i++) {
        voltageArray[i] = analogRead(vPinArray[i]);
    }
    return voltageArray;
} 
float* wMill::getRPM() {
    for (int i = 0; i < length; i++) {
        rpmArray[i] = analogRead(rPinArray[i]);
    }
    return rpmArray;
}
int wMill::getLength() {
    return length;
} 