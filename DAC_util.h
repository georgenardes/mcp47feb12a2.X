/* 
 * File:   DAC_util.h
 * Author: George & Diogo
 *
 * Created on 16 de Maio de 2020, 09:09
 */

#ifndef DAC_UTIL_H
#define	DAC_UTIL_H

const unsigned char DAC_SLAVE_ADDRESS = 0x62;  // endereço padrão do disposito

/**
@Description: Init
 
 *  Inicia uma conexão com o Dispositivo endereçado por DAC_SLAVE_ADDRESS
 
 */
void DAC_Init();


/**
@Description: Start
 
 *  Envia endereço de memoria do escravo a ser escrita/lida   
 
 */
char DAC_Start(unsigned char adress, unsigned char command);

/*
@Description: Write
 
 *  envia um valor digital para o conversor
  
 */
char DAC_Write(unsigned short data);


/**
 @Descrição: Stop
 
 *  Finaliza conexão com o conversor
 
 */
char DAC_Stop();


#endif	/* DAC_UTIL_H */

