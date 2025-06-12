#ifndef WMILL_h
#define WMILL_h

#define MAX_ARRAY_SIZE 5
class wMill {
    public:
    wMill(int acs_pin_1, int cny_pin_1);

    wMill(int acs_pin_1, int cny_pin_1, 
          int acs_pin_2, int cny_pin_2);

    wMill(int acs_pin_1, int cny_pin_1, 
          int acs_pin_2, int cny_pin_2,
          int acs_pin_3, int cny_pin_3);

    wMill(int acs_pin_1, int cny_pin_1, 
          int acs_pin_2, int cny_pin_2,
          int acs_pin_3, int cny_pin_3,
          int acs_pin_4, int cny_pin_4);

    wMill(int acs_pin_1, int cny_pin_1, 
          int acs_pin_2, int cny_pin_2,
          int acs_pin_3, int cny_pin_3,
          int acs_pin_4, int cny_pin_4,
          int acs_pin_5, int cny_pin_5);
    
    float* getVoltage();
    float* getRPM();
    int getLength();
    
    private:
    int length = 0;
    float voltageArray[MAX_ARRAY_SIZE];
    float rpmArray[MAX_ARRAY_SIZE];
    int vPinArray[5];
    int rPinArray[5];
    int acs_pin_1;
    int acs_pin_2;
    int acs_pin_3;
    int acs_pin_4;
    int acs_pin_5;
    int cny_pin_1;
    int cny_pin_2;
    int cny_pin_3;
    int cny_pin_4;
    int cny_pin_5;
};

#endif