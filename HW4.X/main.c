#include<xc.h>           // processor SFR definitions
#include<sys/attribs.h>  // __ISR macro
#include<math.h>
#include"SPI.h"

// DEVCFG0
#pragma config DEBUG = 0b10 // no debugging
#pragma config JTAGEN = 0 // no jtag
#pragma config ICESEL = 0b11 // use PGED1 and PGEC1
#pragma config PWP = 0x1FF // no write protect
#pragma config BWP = 1 // no boot write protect
#pragma config CP = 1 // no code protect

// DEVCFG1
#pragma config FNOSC = 0b011 // use primary oscillator with pll
#pragma config FSOSCEN = 0 // turn off secondary oscillator
#pragma config IESO = 0 // no switching clocks
#pragma config POSCMOD = 0b10 // high speed crystal mode
#pragma config OSCIOFNC = 1 // disable secondary osc
#pragma config FPBDIV = 0b00 // divide sysclk freq by 1 for peripheral bus clock
#pragma config FCKSM = 0b11 // do not enable clock switch
#pragma config WDTPS = 0 // use slowest wdt
#pragma config WINDIS = 1 // wdt no window mode
#pragma config FWDTEN = 0 // wdt disabled
#pragma config FWDTWINSZ = 0b11 // wdt window at 25%

// DEVCFG2 - get the sysclk clock to 48MHz from the 8MHz crystal
#pragma config FPLLIDIV = 1 // divide input clock to be in range 4-5MHz
#pragma config FPLLMUL = 0b111 // multiply clock after FPLLIDIV
#pragma config FPLLODIV = 1 // divide clock after FPLLMUL to get 48MHz
#pragma config UPLLIDIV = 1 // divider for the 8MHz input clock, then multiplied by 12 to get 48MHz for USB
#pragma config UPLLEN = 0 // USB clock on

// DEVCFG3
#pragma config USERID = 0 // some 16bit userid, doesn't matter what
#pragma config PMDL1WAY = 0 // allow multiple reconfigurations
#pragma config IOL1WAY = 0 // allow multiple reconfigurations
#pragma config FUSBIDIO = 1 // USB pins controlled by USB module
#pragma config FVBUSONIO = 1 // USB BUSON controlled by USB module

int main() {
    int i;
     
    //__builtin_disable_interrupts();
    SPI1_init();
   // __builtin_enable_interrupts();
    int f = 0;
    while(1) {
        
        static int i = 0;
        
        
            setVoltage('A',(short)(511.5 + 511.5*sin(i/1000.0*20*PI)));
            if(i<100){
            setVoltage('B',(short)1023.0*i/100);
            }
            else if((i>=100)&&(i<200)){
                i = i-100;
            setVoltage('B',(short)1023.0-(1023.0*i/100));
            }
            else if((i>=200)&&(i<300)){
                i = i-200;
            setVoltage('B',(short)1023.0*i/100);
            }
            else if((i>=300)&&(i<400)){
                i = i-300;
            setVoltage('B',(short)1023.0-(1023.0*i/100));
            }
            else if((i>=400)&&(i<500)){
                i = i-400;
            setVoltage('B',(short)1023.0*i/100);
            }
            else if((i>=500)&&(i<600)){
                i = i-500;
            setVoltage('B',(short)1023.0-(1023.0*i/100));
            }
            else if((i>=600)&&(i<700)){
                i = i-600;
            setVoltage('B',(short)1023.0*i/100);
            }
            else if((i>=700)&&(i<800)){
                i = i-700;
            setVoltage('B',(short)1023.0-(1023.0*i/100));
            }
            else if((i>=800)&&(i<900)){
                i = i-800;
            setVoltage('B',(short)1023.0*i/100);
            }
            else if((i>=900)&&(i<1000)){
                i = i-900;
            setVoltage('B',(short)1023.0-(1023.0*i/100));
            }
            _CP0_SET_COUNT(0);  // Reset the timer
            while(_CP0_GET_COUNT() < 24000){;}  // 24MHz/1kHz = 24000
        
            i++;
            if(i>= 999){
            i=0;}
       
            
        if(i%100 == 0){
        f = 1;}else{
        f = 0;}
                 
//        LATAINV = 0x10;     // turn off/on LED
 //       while(!PORTBbits.RB4){;} // if button is pushed, stop and wait
    }
}