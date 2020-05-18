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

/*
@Description: Inicializa��o

 * manda o pulso de start;
 * manda endere�o do escravo 
  
 */
char I2C_Start(char slave_write_address);

/*
@Description: Inicializa��o

 * Espera opera��o ser completada
  
 */
void I2C_Ready();

/*
@Description: Inicializa��o

 * escreve o valor;
  
 */
char I2C_Write(unsigned char data);

/*
@Description: Inicializa��o

 * serve para dar stop entre um valor mandado em um endere�o e outro
  
 */
char I2C_Stop();
 
/*
@Description: Inicializa��o

 * protocolo de leitura
 */
char I2C_Read(char flag);
 
/*
@Description: Inicializa��o

 * retorna que recebeu valor 
  
 */
void I2C_Ack();
 
/*
@Description: Inicializa��o

 * retorna que deu erro
  
 */
void I2C_Nack();

#endif	/* I2C_UTIL_H */

