#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "modbus.h"


unsigned int str[6];// = { 0x01,0x03,0x00,0x00,0x00,0x00 };


unsigned int crcbuff[] = { 0x00,0x00,0x00,0x00,0x06,0x0d,0xd2,0xe3 };
unsigned int cmd01[] = { 0x01,0x06,0xf1,0x01,0x00,0x03 };
unsigned int cmd02[] = { 0x01,0x03,0x00,0x02,0xfd,0x0d };
unsigned int cmd03 = 0x0106;// 01014d;
unsigned short crcvalue;
unsigned short crch;
unsigned short crcl;
unsigned short crc1;
unsigned short crc2;

int main()
{
	unsigned int data = 0;
	unsigned int length = 0;
	unsigned int data2 = 0;
	unsigned int a, b, c, d;
	unsigned int addr;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	str[0] = 0x01;
	str[1] = d;
	str[2] = a;
	str[3] = b;
	str[4] = 0x00;
	str[5] = c;
	data = cmd01;
	data2 = cmd02;
	length = 6;
	int i;
	i = 0;

	printf("输入命令，功能码通讯地址，需要读取功能码个数，空格隔开\n");
	//while (i == 1 || i == 2 || i ==3 ||i ==0 )
	while (1)
	{
		scanf("%x %x %x", &d, &addr, &c);
		a = 0xff & addr >> 8;
		b = 0xff & addr;
		str[2] = a;
		str[3] = b;
		str[5] = c;
		str[1] = d;
		//str[4] = c;
		//str[5] = d;
		/*switch (i)
		{
		case 1:
			crcvalue = CrcValueByteCalc(data, length);
			break;
		case 2:
			crcvalue = CrcValue(data, length);
			/*crcvalue = (CrcValue(data, length) << 8) | (CrcValue(data, length) >> 8);
			crch = CrcValue(data, length) << 8;
			crcl = CrcValue(data, length) >> 8;
			printf("0x%x\n", crch);
			printf("0x%x\n", crcl);*/
			/*break;
		case 3:
			crcvalue = crc_chk(data, length);
		}*/


		crcvalue = CrcValueByteCalc(str, 6);
		/*crch = CrcValue(str, length);
		crcl = crc_chk(str, length);*/
		crc2 = 0xff & crcvalue;
		crc1 = 0xff & crcvalue >> 8;

		//printf("0x%x\n ", crcvalue);
		printf("[0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x]\n"
			, str[0], str[1], str[2], str[3], str[4], str[5], crc1, crc2);
		//printf("next\n");
	}

	return 0;
}
