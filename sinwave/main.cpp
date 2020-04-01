#include "mbed.h"
AnalogOut Aout(DAC0_OUT);
AnalogIn Ain(A0);
DigitalIn  Switch(SW3);
Serial pc( USBTX, USBRX );
DigitalOut redLED(LED1);

DigitalOut greenLED(LED2);
BusOut display(D6, D7, D9, D10, D11, D5, D4, D8);

char table[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};


int main(){
 // int A[5] = {3,5,1,6,7};
  int data[1001];
  int count=0;
  for(int i=0;i<1000;i++){
    data[i] = Ain;
    wait(0.001);
  //  if(data[i]>=0.45) count++;
    pc.printf("%1.3f\r\n",Ain);
  }

  while(1){

     if(Switch == 0 ){
      
      greenLED = 0;
      redLED = 1;
      for(int i=0;i<=4;i++){
        display = table[3];
        
        wait(0.5);
      }
    }

    else{
      redLED = 0;
      greenLED = 1;
      display = table[0];
    }
    for(float i=0; i<2; i+=0.05 ){

      Aout = 0.5 + 0.5*sin(i*3.14159);

      wait(0.001);
    }



   // pc.printf("%1.3f\r\n",count);
  }


}

