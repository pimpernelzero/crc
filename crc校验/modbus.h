#ifndef __MODBUS__H
#define __MODBUS__H


//380 crcУ���㷨

unsigned int CrcValueByteCalc(const unsigned int* data, unsigned int length);

/*------------------------------------------------------------------------------------------*/

//crc16�㷨

unsigned int CrcValue(const unsigned int* data, unsigned int length);  // ��֪���

//�ǲ��
unsigned int crc_chk(unsigned int* data_value, unsigned int length);

#endif
