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
    I2C_Init();

    unsigned short i = 0, k = 1023;
    signed char j = 4, j2 = 4;
    
    while(1) {
        DAC_Init(); 
        DAC_Start(0x00,0x00);
        DAC_Write(i);
        I2C_Stop();
        __delay_ms(5);
        
        DAC_Init();
        DAC_Start(0x01,0x00);
        DAC_Write(k);
        I2C_Stop();
        
        i = i+j;
        k = k + j2;
        if(i < 4 ){
            j = 4;
            i = 0;
        }
        if(k < 4){
            j2 = 4;
            k = 0;
        }
        
        if(k > 1023 ){
            j2 = -4;
            k = 1023;
        }
        
        
        if(i > 1023){
            j = -4; 
            i = 1023;
        } 
         
        
        Nop();
        
        __delay_ms(5);
    }
    
    return;    
}
