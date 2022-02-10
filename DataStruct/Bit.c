#include<stdio.h>

struct BYTE_struct{
    unsigned char BYTE4;
    unsigned char BYTE3;
    unsigned char BYTE2;
    unsigned char BYTE1;
};
union LongFlag{
    unsigned long All;
    struct BYTE_struct BYTEMODE;
};
int main(){
    union LongFlag flag;
    flag.All = 0x01234567;
    flag.BYTEMODE.BYTE1 = 0xFA;
    flag.BYTEMODE.BYTE2 &= 0xAA;
    flag.BYTEMODE.BYTE3 &= 0x55;
    flag.BYTEMODE.BYTE4 = 0x11;
    printf("%lx\t", flag.All);
    return 0;
}