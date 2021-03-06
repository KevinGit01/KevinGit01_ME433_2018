#include <xc.h>
#include "LSM6DS333.h"

//initialize I/O expander
void LSM6DS333_init(void) {
  // Turn off analog input (since for i2c we still use the i2c2)
  ANSELBbits.ANSB2 = 0;
  ANSELBbits.ANSB3 = 0;

  // Initialize the i2c
  i2c_master_setup();

  // Initialize the accelerometer
  i2c_master_start();                   // start
  i2c_master_send(IMU_ADDR << 1);       // OP + W: R/W = 0 = write
  i2c_master_send(0x10);                // ADDR: CTRL1_XL register for imu accelerometer
  i2c_master_send(0x82);                // CTRL1_XL register: [1 0 0 0 0 0 1 0], ORD_XL = [1 0 0 0] (1.66kHz), FS_XL = [0 0] (4g), BW_XL = [1 0] (100Hz filter)
  i2c_master_stop();

  // Initialize gyroscope
  i2c_master_start();                   // start
  i2c_master_send(IMU_ADDR << 1);       // OP + W: R/W = 0 = write
  i2c_master_send(0x11);                // ADDR: CTRL2_G register for imu gyroscope
  i2c_master_send(0x88);                // CT RL2_G register: [1 0 0 0 1 0 0 0], ORD_G = [1 0 0 0] (1.66kHz), FS_G = [1 0] (1000dps), BW_XL = [0 0] (no filter)
  i2c_master_stop();

  // Initialize IF_INC bit (read multiple registers without specifying each register location)
  i2c_master_start();                   // start
  i2c_master_send(IMU_ADDR << 1);       // OP + W: R/W = 0 = write
  i2c_master_send(0x12);                // ADDR: CTRL3_C register for reading multiple registers
  i2c_master_send(0x04);                // CTRL3_C register: default value [0 0 0 0 0 1 0 0] where IF_INC = 1
  i2c_master_stop();
}

void I2C_read_multiple(unsigned char address, unsigned char regis, unsigned char * data, int length){
    char i;
    i2c_master_start();
    i2c_master_send(address<<1);   // R/W = 0 = write
    i2c_master_send(regis);  // 0x20 = OUT_TEMP_L
    i2c_master_restart(); 
    i2c_master_send((address<<1)|1); // R/W = 1 = read
    for(i=0;i<length;i++){
        data[i] = i2c_master_recv(); // receive a byte from GP7
        if(i!=(length-1))
            i2c_master_ack(0);
    }
    i2c_master_ack(1); // send NACK to slave
    i2c_master_stop();
}

float getxXL(unsigned char * data) { // convert x-acceleration 
    signed short x = data[9]<<8 | data[8];
    return x*(2.0/32757.0);
}

float getyXL(unsigned char * data) { // convert y-acceleration 
    signed short y = data[11]<<8 | data[10];
    return y*(2.0/32757.0);
}
