#include<Arduino.h>
const int A_pin = 5;   
const int B_pin = 6;
const int C_pin = 7;
const int D_pin = 8;

void setup() {
  pinMode(A_pin, OUTPUT);
  pinMode(B_pin, OUTPUT);
  pinMode(C_pin, OUTPUT);
  pinMode(D_pin, OUTPUT);


  int P = 0;   
  int Q = 0;  
  int R = 1;   

  int f = P ^ Q ^ R;

  digitalWrite(A_pin, f); 
  digitalWrite(B_pin, LOW);
  digitalWrite(C_pin, LOW);
  digitalWrite(D_pin, LOW);
}

void loop() {

}

