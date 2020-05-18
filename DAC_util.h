/* 
 * File:   DAC_util.h
 * Author: George & Diogo
 *
 * Created on 16 de Maio de 2020, 09:09
 */

#ifndef DAC_UTIL_H
#define	DAC_UTIL_H

const unsigned char DAC_SLAVE_ADDRESS = 0x62;  // do datasheet 

void DAC_Init();

char DAC_Start(unsigned char endereco);

char DAC_Write(unsigned short data);
 
char DAC_Read(char flag);


#endif	/* DAC_UTIL_H */

