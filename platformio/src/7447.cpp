#include <Arduino.h>
const int PIN_A = 8;
const int PIN_B = 9;
const int PIN_C = 10;
const int PIN_D = 11;

void setup() {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
}

void sendBCD(int digit) {
  digitalWrite(PIN_A, digit & 1);         
  digitalWrite(PIN_B, (digit >> 1) & 1);  
  digitalWrite(PIN_C, (digit >> 2) & 1);  
  digitalWrite(PIN_D, (digit >> 3) & 1);  
}

void loop() {
  for (int i = 0; i < 8; i++) {
    int P = (i >> 2) & 1;
    int Q = (i >> 1) & 1;
    int R = (i >> 0) & 1;
    int f = !(Q || R);

   
    sendBCD(f);

    delay(1000);
  }
}


