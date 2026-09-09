#include "STD_TYPES.h"
#include "BITMATH.h"
#include "SPI.h"


void SPI_InitMaster(void)
{
	
	SET_BIT(SPCR_REG, 6);

	CLR_BIT(SPCR_REG, 5);

	SET_BIT(SPCR_REG, 4);

	
	CLR_BIT(SPCR_REG, 3);
	CLR_BIT(SPCR_REG, 2);

	
	CLR_BIT(SPCR_REG, 1);
	SET_BIT(SPCR_REG, 0);
}

void SPI_InitSlave(void)
{	
	SET_BIT(SPCR_REG, 6);

	CLR_BIT(SPCR_REG, 5);

	CLR_BIT(SPCR_REG, 4);
}

void SPI_SendChar(u8 data)
{
	SPDR_REG = data;

	while (GET_BIT(SPSR_REG, 7) == 0);
}

u8 SPI_GetChar(void)
{
	while (GET_BIT(SPSR_REG, 7) == 0);
	
	return SPDR_REG;
}