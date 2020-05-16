#include "i2c_util.h"

void I2C_Init() {
    ADCON1 = 0x0F;
    
    /* Set up I2C lines by setting as input */            
    TRISC3 = 1; 
    TRISC4 = 1;
    
    /* Slew rate disabled, other bits are cleared */
    SSPSTAT = 0x80; 
    
    /* Enable SSP port for I2C Master mode, clock = FOSC / (4 * (SSPADD+1))*/
    SSPCON1 = 0x28;         
    SSPCON2 = 0x00;
    
    /* Clock 100 kHz */
    SSPADD = BIT_RATE;  
    
    /* Enable SSPIF interrupt */
    SSPIE = 1;         
    SSPIF = 0;
}

char I2C_Start(char slave_write_address) {
    /* Send start pulse */
    SSPCON2bits.SEN = 1; 
    
    /* Wait for completion of start pulse */
    while (SSPCON2bits.SEN); 
    
    /* clear interrupt flag*/
    SSPIF = 0;
    
    /* Check whether START detected last */
    if (!SSPSTATbits.S) 
        return 0;           // Return 0 to indicate start failed 
    
    /* Write slave device address with write to communicate */
    return (I2C_Write(slave_write_address)); 
}

void I2C_Ready() {
    /* Wait for operation complete */
    while (!SSPIF); 
    
    /* Clear SSPIF interrupt flag*/
    SSPIF = 0; 
}   

char I2C_Write(unsigned char data) {
    /* Write data to SSPBUF*/
    SSPBUF = data; 
    
    /* I2C Bus Ready */
    I2C_Ready();
    
    /* Check for acknowledge bit*/
    if (ACKSTAT) 
        return 1;
    else
        return 2;
}

char I2C_Stop() {       
    /* Stop communication*/
    PEN = 1; 
    
    /* Wait for end of stop pulse*/
    while (PEN); 
    
    /* clear interruption  flag*/
    SSPIF = 0;
    
    /* Check whether STOP is detected last */
    if (!SSPSTATbits.P) 
        return 0;           // If not return 0 to indicate start failed
}

char I2C_Read(char flag) {
    int buffer = 0;
    
    /* Enable receive */
    RCEN = 1; 

    /* Wait for buffer full flag which when complete byte received */
    while (!SSPSTATbits.BF);
    
    /* Copy SSPBUF to buffer */
    buffer = SSPBUF; 

    /* Send acknowledgment or negative acknowledgment after read to 
    continue or stop reading */
    if (flag == 0)
        I2C_Ack();
    else
        I2C_Nack();
    
    I2C_Ready();
    
    return (buffer);
}

void I2C_Ack() {
    ACKDT = 0; /* Acknowledge data 1:NACK,0:ACK */
    ACKEN = 1; /* Enable ACK to send */
    while (ACKEN);
}

void I2C_Nack() {
    ACKDT = 1; /* Acknowledge data 1:NACK,0:ACK */
    ACKEN = 1; /* Enable ACK to send */
    while (ACKEN);
}
