#ifndef SPI_H_
#define SPI_H_

#include "std_types.h"
#define SPCR_REG   (*((volatile u8*)0x2D))
#define SPSR_REG   (*((volatile u8*)0x2E))
#define SPDR_REG   (*((volatile u8*)0x2F))
void SPI_InitMaster(void);
void SPI_InitSlave(void);
u8 SPI_GetChar(void);
void SPI_SendChar(u8 data);

#endif