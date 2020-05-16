/*
 * File:   main.c
 * Author: George & Diogo
 *
 * Created on 12 de Maio de 2020, 12:37
 */


#include <xc.h>
#include "config.h"
#include "i2c_util.h"

void main(void) {
    I2C_Init();
    
    I2C_Start(0xA0);
    
    I2C_Write(0xF);
    
    return;    
}
