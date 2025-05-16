#ifndef BITWISE_HEDEAR
#define BITWISE_HEADER

#define setReg(reg,val) reg |= val
#define clrReg(reg,val) reg &= ~val
#define getBit(reg,bit) (reg>>bit)&1
#define clrBit(reg,bit) reg&= ~(bit<<1)
#define setBit(reg,bit) reg|= (bit<<1)

#endif
