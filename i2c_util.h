/* 
 * File:   i2c_util.h
 * Author: George & Diogo
 *
 * Created on 15 de Maio de 2020, 12:15
 */

#ifndef I2C_UTIL_H
#define	I2C_UTIL_H

#include <xc.h> 
#include "config.h"


/* declara��o de defines */
#define BIT_RATE 39         // clock = FOSC/(4 * (SSPADD + 1))


/* declara��o de func�es aqui */

/**
@Description: Inicializa��o

Configura PORTB.0 e PORTB.1 como pino de entrada.
Configura tamb�m o registro SSPSTAT e SSPCON2.
Habilita o I2C configurando o bit SSPEN no registro SSPCON1. 
Seleciona tamb�m o modo mestre / escravo.
Define a frequ�ncia da comunica��o I2C carregando o valor no registro SSPADD no modo mestre.
  
 */
void I2C_Init();

char I2C_Start(char slave_write_address);

void I2C_Ready();
 
char I2C_Write(unsigned char data);
 
char I2C_Stop();
 
char I2C_Read(char flag);
 
void I2C_Ack();
 
void I2C_Nack();

#endif	/* I2C_UTIL_H */

