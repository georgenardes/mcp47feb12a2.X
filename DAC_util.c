#include "DAC_util.h"
#include "i2c_util.h"

void DAC_Init(){
    // SAIDA
    TRISC5 = 0;
    
    I2C_Start(DAC_SLAVE_ADDRESS<<1);    //envia os 7 bit menos sig        
}

char DAC_Start(unsigned char adress, unsigned char command){ 
    char variable = ' ';
    variable = adress << 3 |command << 1 ;
    return I2C_Write(variable);
}

char DAC_Write(unsigned short data){
    char result = 0;
    result = result | I2C_Write((unsigned char)(data>>8));
    result = result |I2C_Write(data);           
    return result;
}
 
