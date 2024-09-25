#include <stdio.h>
unsigned char crc_table[256] = {
			0x00, 0x1d, 0x3a, 0x27, 0x74, 0x69, 0x4e, 0x53, 0xe8, 0xf5,
			0xd2, 0xcf, 0x9c, 0x81, 0xa6, 0xbb, 0xcd, 0xd0, 0xf7, 0xea,
			0xb9, 0xa4, 0x83, 0x9e, 0x25, 0x38, 0x1f, 0x02, 0x51, 0x4c,
			0x6b, 0x76, 0x87, 0x9a, 0xbd, 0xa0, 0xf3, 0xee, 0xc9, 0xd4,
			0x6f, 0x72, 0x55, 0x48, 0x1b, 0x06, 0x21, 0x3c, 0x4a, 0x57,
			0x70, 0x6d, 0x3e, 0x23, 0x04, 0x19, 0xa2, 0xbf, 0x98, 0x85,
			0xd6, 0xcb, 0xec, 0xf1, 0x13, 0x0e, 0x29, 0x34, 0x67, 0x7a,
			0x5d, 0x40, 0xfb, 0xe6, 0xc1, 0xdc, 0x8f, 0x92, 0xb5, 0xa8,
			0xde, 0xc3, 0xe4, 0xf9, 0xaa, 0xb7, 0x90, 0x8d, 0x36, 0x2b,
			0x0c, 0x11, 0x42, 0x5f, 0x78, 0x65, 0x94, 0x89, 0xae, 0xb3,
			0xe0, 0xfd, 0xda, 0xc7, 0x7c, 0x61, 0x46, 0x5b, 0x08, 0x15,
			0x32, 0x2f, 0x59, 0x44, 0x63, 0x7e, 0x2d, 0x30, 0x17, 0x0a,
			0xb1, 0xac, 0x8b, 0x96, 0xc5, 0xd8, 0xff, 0xe2, 0x26, 0x3b,
			0x1c, 0x01, 0x52, 0x4f, 0x68, 0x75, 0xce, 0xd3, 0xf4, 0xe9,
			0xba, 0xa7, 0x80, 0x9d, 0xeb, 0xf6, 0xd1, 0xcc, 0x9f, 0x82,
			0xa5, 0xb8, 0x03, 0x1e, 0x39, 0x24, 0x77, 0x6a, 0x4d, 0x50,
			0xa1, 0xbc, 0x9b, 0x86, 0xd5, 0xc8, 0xef, 0xf2, 0x49, 0x54,
			0x73, 0x6e, 0x3d, 0x20, 0x07, 0x1a, 0x6c, 0x71, 0x56, 0x4b,
			0x18, 0x05, 0x22, 0x3f, 0x84, 0x99, 0xbe, 0xa3, 0xf0, 0xed,
			0xca, 0xd7, 0x35, 0x28, 0x0f, 0x12, 0x41, 0x5c, 0x7b, 0x66,
			0xdd, 0xc0, 0xe7, 0xfa, 0xa9, 0xb4, 0x93, 0x8e, 0xf8, 0xe5,
			0xc2, 0xdf, 0x8c, 0x91, 0xb6, 0xab, 0x10, 0x0d, 0x2a, 0x37,
			0x64, 0x79, 0x5e, 0x43, 0xb2, 0xaf, 0x88, 0x95, 0xc6, 0xdb,
			0xfc, 0xe1, 0x5a, 0x47, 0x60, 0x7d, 0x2e, 0x33, 0x14, 0x09,
			0x7f, 0x62, 0x45, 0x58, 0x0b, 0x16, 0x31, 0x2c, 0x97, 0x8a,
			0xad, 0xb0, 0xe3, 0xfe, 0xd9, 0xc4
};
void getCRCTable(unsigned char crcdata[], int len)
{	
	unsigned char crc = 0xFF;

	for (int i = 0; i < len; i++) 
	{
		printf("CRCtable %d ", i + 1);
		crc = crc_table[crc ^ crcdata[i]];
		printf("%X\n", crc);
	}
	crc = crc ^ 0xFF;
	printf("Rseult %X\n", crc);
}
unsigned char CRC8_SAEJ1850(unsigned char* crcdata, unsigned int len) {
	unsigned short i, j;
	unsigned char crc = 0xFF;

	for (i = 0; i < len; i++) {
		crc = crc ^ (*crcdata);
		crcdata++;
		for (j = 0; j < 8; j++)
		{
			if (crc & 0x80) {
				crc = (crc << 1) ^ 0x1D;
			}
			else {
				crc = crc << 1;
			}
		}
	}


	return crc ^ 0xFF;
}
int main(void) 
{
	int i;

	unsigned char crcdata1[2] = { 0x00, 0x00 };
	unsigned char crcdata2[3] = { 0xF2, 0x01, 0x83 };
	unsigned char crcdata3[4] = { 0x0F, 0xAA, 0x00, 0x55 };
	unsigned char crcdata4[4] = { 0x00, 0xFF, 0x55, 0x11 };
	unsigned char crcdata5[9] = { 0x33, 0x22, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF };
	unsigned char crcdata6[3] = { 0x92, 0x6B, 0x55 };
	unsigned char crcdata7[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
	unsigned char crcdata8[15] = { 0x11, 0x11, 0x11, 0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11 };
	printf("#CRC 직접 계산 예시 01 %X\n",CRC8_SAEJ1850(crcdata1, 2));
	getCRCTable(crcdata1, 2);
	printf("--------------------------\n");
	printf("#CRC 직접 계산 예시 02 %X\n", CRC8_SAEJ1850(crcdata2, 3));
	getCRCTable(crcdata2, 3);
	printf("--------------------------\n");
	printf("#CRC 직접 계산 예시 03 %X\n", CRC8_SAEJ1850(crcdata3, 4));
	getCRCTable(crcdata3, 4);
	printf("--------------------------\n");
	printf("#CRC 직접 계산 예시 04 %X\n", CRC8_SAEJ1850(crcdata4, 4));
	getCRCTable(crcdata4, 4);
	printf("--------------------------\n");
	printf("#CRC 직접 계산 예시 05 %X\n", CRC8_SAEJ1850(crcdata5, 9));
	getCRCTable(crcdata5, 9);
	printf("--------------------------\n");
	printf("#CRC 직접 계산 예시 06 %X\n", CRC8_SAEJ1850(crcdata6, 3));
	getCRCTable(crcdata6, 3);
	printf("--------------------------\n");
	printf("#CRC 직접 계산 예시 07 %X\n", CRC8_SAEJ1850(crcdata7, 4));
	getCRCTable(crcdata7, 4);
	printf("--------------------------\n");
	printf("#CRC 직접 계산 예시 08 %X\n", CRC8_SAEJ1850(crcdata8, 15));
	getCRCTable(crcdata8, 15);

	return 0;
}

