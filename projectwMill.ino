#include <Arduino.h>
#include "wMill.h"

  bool voltageManipulation = true;
const int sensorPin = 1;
const int adcPin = 2;
float totEnergie[5] = {0};
long lastMeasurement[5] = {0};
float interval[5];
long prevMillis = 0;
long morePrevMillis = 0;
float RPM = 0;
float* lesVoltages;
float* lesRPMs;
int lengte = 0;
wMill wMill(adcPin, sensorPin);

void setup() {
  Serial.begin(115200);
  pinMode(4, OUTPUT);
  lesVoltages = new float[5];
  lesRPMs = new float[5];
  lengte = wMill.getLength();
}


void loop() {

  float spanning[5];
  float stroom[5];
  float vermogen[5];
  float gemEnergie[5];
  
  getVPP();
  calcRPM();
  if(millis() - morePrevMillis >= 1000) {
    digitalWrite(4, HIGH);
    morePrevMillis = millis();
  }
  if(millis() + 100 - morePrevMillis >= 1000) {
    digitalWrite(4, LOW);
  }

  if(millis() - prevMillis >= 1000) {
    Serial.println("\t\tVoltage\tCurrent\tPower\tTotal\tAverage\tRPM");
  for (int i = 0; i < 5; i++) {
    if (i < lengte) {
      stroom[i] = lesVoltages[i]*25;
      vermogen[i] = lesVoltages[i]*stroom[i];
      if(vermogen[i] > 0 ) {
        totEnergie[i] = totEnergie[i] + vermogen[i]/1000.0;
      }
      gemEnergie[i] = (1000000.0*totEnergie[i])/millis();
      Serial.print("Windmolen_" + String(i + 1) + ":\t");
      Serial.print(lesVoltages[i]); Serial.print("V\t");
      Serial.print(stroom[i]); Serial.print("mA\t");
      Serial.print(vermogen[i]); Serial.print("mW\t");
      Serial.print(totEnergie[i]); Serial.print("J\t");
      Serial.print(gemEnergie[i]); Serial.print ("mJ\t");
      Serial.print(lesRPMs[i]); Serial.println("rpm");
      lesRPMs[i] = 0;
    }
    else {
      Serial.println("Windmolen_" + String(i + 1) + ": \tN/A\tN/A\tN/A\tN/A\tN/A\tN/A");
    }
  } 
  prevMillis = millis();
  }
}


void calcRPM() {
  float* resultaat = wMill.getRPM();
  for (int i = 0; i < lengte; i++) {
    if(resultaat[i] <= 3900) {
      interval[i] = (millis() - lastMeasurement[i]);
      if(interval[i] > 5 && interval[i] < 20000) {
        if(60000/(3*interval[i])< 800) {
          lesRPMs[i] = 60000/(3*interval[i]);
        }
      }
      lastMeasurement[i] = millis();
    }
  }
}


void getVPP()
{
  float* analogValues = wMill.getVoltage();
  for (int i = 0; i < lengte; i++) {
    lesVoltages[i] = (analogValues[i]*3.3)/4096.0;
  }
}