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


/* declaração de defines */
#define BIT_RATE 39         // clock = FOSC/(4 * (SSPADD + 1))


/* declaração de funcões aqui */

/**
@Description: Inicialização

Configura PORTB.0 e PORTB.1 como pino de entrada.
Configura também o registro SSPSTAT e SSPCON2.
Habilita o I2C configurando o bit SSPEN no registro SSPCON1. 
Seleciona também o modo mestre / escravo.
Define a frequência da comunicação I2C carregando o valor no registro SSPADD no modo mestre.
  
 */
void I2C_Init();

/*
@Description: Inicialização

 * manda o pulso de start;
 * manda endereço do escravo 
  
 */
char I2C_Start(char slave_write_address);

/*
@Description: Inicialização

 * Espera operação ser completada
  
 */
void I2C_Ready();

/*
@Description: Inicialização

 * escreve o valor;
  
 */
char I2C_Write(unsigned char data);

/*
@Description: Inicialização

 * serve para dar stop entre um valor mandado em um endereço e outro
  
 */
char I2C_Stop();
 
/*
@Description: Inicialização

 * protocolo de leitura
 */
char I2C_Read(char flag);
 
/*
@Description: Inicialização

 * retorna que recebeu valor 
  
 */
void I2C_Ack();
 
/*
@Description: Inicialização

 * retorna que deu erro
  
 */
void I2C_Nack();

#endif	/* I2C_UTIL_H */

