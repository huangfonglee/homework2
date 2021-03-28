#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;

AnalogOut aout(PA_4);
//AnalogOut Rvin(D6);

DigitalIn B1(A2);
DigitalIn B2(A1);
DigitalIn B3(A0);
DigitalIn mypin(USER_BUTTON);

AnalogIn VIN(A3);


int main(){

    int a = 0;

    uint16_t sample = 0;
    float sample2[100];

    aout = 1;

   while(!B1 && !B2 && !B3); //while (1){

        if (B1 == 1){
            a = 1;

        }

        else if (B2 == 1){
            a = 10;
        }

        else if (B3 == 1){
            a = 100;
        }

    
        

        uLCD.color(BLUE);  
        uLCD.background_color(WHITE);
        uLCD.textbackground_color(WHITE);
        uLCD.cls();
        // basic printf demo = 16 by 18 characters on screen
        uLCD.locate(1, 1);
        uLCD.text_width(4); //4X size text
        uLCD.text_height(4);
        uLCD.color(GREEN);
        uLCD.printf("\n%d\n", a); //Default Green on black text
        /*fr (int i=30; i>=0; --i) {
            uLCD.locate(1,2);
            uLCD.printf("%2d",i);
            ThisThread::sleep_for(500ms);
        }*/

    //}
    
    while(1){
            if (!mypin) break;
            for (int i = 0; i < 80; i++) {
                  sample = (uint16_t)(59578 * i / 80);
                  aout.write_u16(sample);
                  sample2[i] = VIN;
                  wait_us(10000/a);
            }
            for (int i = 0; i < 20; i++) {
                  sample = (uint16_t)(59578 * (20 - i) / 20);
                  aout.write_u16(sample);
                  sample2[i + 80] = VIN;
                  
                  wait_us(10000/a);
            }
      }

      for (int i = 0; i < 100; i++) {
            printf("%f\r\n", sample2[i]);
      }
}