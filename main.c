/*
 * File:   main.c
 * Author: George & Diogo
 *
 * Created on 12 de Maio de 2020, 12:37
 */


#include <xc.h>
#include "config.h"
#include "i2c_util.h"
#include "DAC_util.h"

void main(void) {
    // SAIDA
    TRISC5 = 0;
    
    I2C_Init();

    unsigned short i = 0;
    signed char j = 4;
    
    while(1) {
        
        DAC_Init(); 
        DAC_Start(0x00,0x00); //first adress, command write
        DAC_Write(i);
        DAC_Stop();
        
        DAC_Init();
        DAC_Start(0x01,0x00); //second adress, command write
        DAC_Write(1023 - i);
        DAC_Stop();
        
        i = i+j;
        
        if(i < 4 ){
            j = 4;
            i = 0;
        }                                        
        if(i > 1023){
            j = -4; 
            i = 1023;
        } 
         
        __delay_ms(5);
    }
    
    return;    
}
