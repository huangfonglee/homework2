#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;

AnalogOut aout(PA_4);
//AnalogOut Rvin(D6);

DigitalIn But1(A2);
DigitalIn But2(A1);
DigitalIn But3(A0);
DigitalIn mypin(USER_BUTTON);

AnalogIn VIN(A3);


int main(){

    int frequency = 20;

    uint16_t sample = 0;
    float sample2[200];

    aout = 1;

    while(1){

        if (But1 == 1){
            frequency += 10;
            uLCD.color(BLUE);  
            uLCD.background_color(WHITE);
            uLCD.textbackground_color(WHITE);
            uLCD.cls();
            // basic printf demo = 16 by 18 characters on screen
            uLCD.locate(1, 1);
            uLCD.text_width(4); //4X size text
            uLCD.text_height(4);
            uLCD.color(GREEN);
            uLCD.printf("\n%d\n", frequency);
        }

        if (But2 == 1){

            uLCD.color(BLUE);  
            uLCD.background_color(WHITE);
            uLCD.textbackground_color(WHITE);
            uLCD.cls();
            // basic printf demo = 16 by 18 characters on screen
            uLCD.locate(1, 1);
            uLCD.text_width(4); //4X size text
            uLCD.text_height(4);
            uLCD.color(GREEN);
            uLCD.printf("\n%d\n", frequency);
            break;

        }

        if (But3 == 1){

            frequency -= 10;
            uLCD.color(BLUE);  
            uLCD.background_color(WHITE);
            uLCD.textbackground_color(WHITE);
            uLCD.cls();
            // basic printf demo = 16 by 18 characters on screen
            uLCD.locate(1, 1);
            uLCD.text_width(4); //4X size text
            uLCD.text_height(4);
            uLCD.color(GREEN);
            uLCD.printf("\n%d\n", frequency);

        }


    }

   

    
        

        /*uLCD.color(BLUE);  
        uLCD.background_color(WHITE);
        uLCD.textbackground_color(WHITE);
        uLCD.cls();
        // basic printf demo = 16 by 18 characters on screen
        uLCD.locate(1, 1);
        uLCD.text_width(4); //4X size text
        uLCD.text_height(4);
        uLCD.color(GREEN);
        uLCD.printf("\n%d\n", a); //Default Green on black text*/
        /*fr (int i=30; i>=0; --i) {
            uLCD.locate(1,2);
            uLCD.printf("%2d",i);
            ThisThread::sleep_for(500ms);
        }*/

    //}
    printf("%d\r\n", frequency);
    while(1){
            if (!mypin) break;
            for (int i = 0; i < 40; i++) {
                  sample = (uint16_t)(59578 * i / 40);
                  aout.write_u16(sample);
                  sample2[i] = VIN;
                  wait_us(20000/frequency);
            }
            for (int i = 0; i < 10; i++) {
                  sample = (uint16_t)(59578 * (10 - i) / 10);
                  aout.write_u16(sample);
                  sample2[i + 40] = VIN;
                  
                  wait_us(20000/frequency);
            }
            for (int i = 0; i < 40; i++) {
                  sample = (uint16_t)(59578 * i / 40);
                  aout.write_u16(sample);
                  sample2[i + 50] = VIN;
                  wait_us(20000/frequency);
            }
            for (int i = 0; i < 10; i++) {
                  sample = (uint16_t)(59578 * (10 - i) / 10);
                  aout.write_u16(sample);
                  sample2[i + 90] = VIN;
                  
                  wait_us(20000/frequency);
            }
            for (int i = 0; i < 40; i++) {
                  sample = (uint16_t)(59578 * i / 40);
                  aout.write_u16(sample);
                  sample2[i + 100] = VIN;
                  wait_us(20000/frequency);
            }
            for (int i = 0; i < 10; i++) {
                  sample = (uint16_t)(59578 * (10 - i) / 10);
                  aout.write_u16(sample);
                  sample2[i + 140] = VIN;
                  
                  wait_us(20000/frequency);
            }
            for (int i = 0; i < 40; i++) {
                  sample = (uint16_t)(59578 * i / 40);
                  aout.write_u16(sample);
                  sample2[i + 150] = VIN;
                  wait_us(20000/frequency);
            }
            for (int i = 0; i < 10; i++) {
                  sample = (uint16_t)(59578 * (10 - i) / 10);
                  aout.write_u16(sample);
                  sample2[i + 190] = VIN;
                  
                  wait_us(20000/frequency);
            }
      }

      for (int i = 0; i < 200; i++) {
            printf("%f\r\n", sample2[i]);
      }
}