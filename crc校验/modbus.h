#ifndef __MODBUS__H
#define __MODBUS__H


//380 crc校验算法

unsigned int CrcValueByteCalc(const unsigned int* data, unsigned int length);

/*------------------------------------------------------------------------------------------*/

//crc16算法

unsigned int CrcValue(const unsigned int* data, unsigned int length);  // 已知最佳

//非查表法
unsigned int crc_chk(unsigned int* data_value, unsigned int length);

#endif
