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
            
    unsigned short i = 0;
    signed char j = 4;
    
    while(1) {
        DAC_Init();
        DAC_Start(0x00);
        DAC_Write(i);
        I2C_Stop();
        
        DAC_Init();
        DAC_Start(0x01);
        DAC_Write(i+2);
        I2C_Stop();
        
        i = i+j;
        
        if(i < 4){
            j = 4;
            i = 0;
        }
        
        if(i > 1023){
            j = -4; 
            i = 1023;
        } 
         
        
        //Nop();
        
        __delay_ms(1000);
    }
    
    return;    
}
