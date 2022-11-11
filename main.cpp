/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 500 
#define pinLED1 PA_10
#define pinLED2 PB_5
#define pinLED3 PB_10

#define pinBT1 PA_15
#define pinBT2 PB_7
#define pinBT3 PC_2

BusIn botones(pinBT3,pinBT2,pinBT1);
BusOut leds(pinLED3,pinLED2,pinLED1);



int main()
{
  

    while (true)
    {
        int estadoBotones=botones;
        leds=~estadoBotones;
     
        printf("Valor botones:%d, ",estadoBotones);
        if(estadoBotones&0b100){
            printf("BT3 1, ");
        }
        else{
            printf("BT3 0, ");
        }

        if(estadoBotones&2){
            printf("BT2 1, ");
        }
        else{
            printf("BT2 0, ");
        }
        if(estadoBotones&0x1){
            printf("BT1 1\n");
        }
        else{
            printf("BT1 0\n");
        }
        ThisThread::sleep_for(100);
    }
}
