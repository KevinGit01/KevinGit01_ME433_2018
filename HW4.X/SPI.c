#include <proc/p32mx250f128b.h>

#include "SPI.h"
#define CS LATBbits.LATB8  
void initSPI1(){

  TRISBbits.TRISB8 = 0;
  
  CS = 1;

  // Master - SPI4, pins are: SDI4(F4), SDO4(F5), SCK4(F13).  
  // we manually control SS4 as a digital output (F12)
  // since the pic is just starting, we know that spi is off. We rely on defaults here
 
  // setup spi4
  SPI1CON = 0;              // turn off the spi module and reset it
  SPI1BUF;                  // clear the rx buffer by reading from it
  RPA2Rbits.RPA2R = 0b0011; // assign pin 9 as SDO
  SDI1Rbits.SDI1R = 0b0000; // assign pin 3 to SDI
  SPI1BRG = 0x1;            // baud rate to 10 MHz [SPI4BRG = (80000000/(2*desired))-1]
  SPI1STATbits.SPIROV = 0;  // clear the overflow bit
  SPI1CONbits.CKE = 1;      // data changes when clock goes from hi to lo (since CKP is 0)
  SPI1CONbits.MSTEN = 1;    // master operation
  SPI1CONbits.MSSEN = 0;
  SPI1CONbits.MODE32 = 0;
  SPI1CONbits.MODE16 = 1;   //16 bit SPI
  SPI1CONbits.ON = 1;       // turn on spi 4

}

char SPI1_IO(char write){
    
  SPI1BUF = write;
  while(!SPI1STATbits.SPIRBF) { // wait to receive the byte
    ;
  }
  return SPI1BUF; 
}