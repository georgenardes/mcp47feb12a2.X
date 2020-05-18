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


/**
@Description: Inicializa��o

 * Configura endere�o de memoria do escravo a ser escrita com o comando
 * adress:0x00 � para primeiro endere�o de memoria
 * adress:0x01 � para segundo endere�o da memoria
 * command 0x00 para escrita
  
 */
char DAC_Start(unsigned char adress, unsigned char command);

char DAC_Write(unsigned short data);
 
char DAC_Read(char flag);


#endif	/* DAC_UTIL_H */

