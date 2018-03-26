#include "SpiTest.h"
#include <bcm2835.h>


#define GPIOCONFIG 		0b0100000000000111
#define ADCCONFIG 		0b0010000000001000
#define DACCONFIG 		0b0010000100000000
#define GPCCONFIG 		0b0001100000000000
#define ADCSEQUENCE 	0b0001001000001000
#define ONE 			0b0100100000000001
#define TWO 			0b0100100000000010
#define THREE 			0b0100100000000011
#define FOUR 			0b0100100000000100
#define FIVE 			0b0100100000000101
#define SIX 			0b0100100000000110
#define SEVEN 			0b0100100000000111
#define WORDSIZE 		2U

unsigned short config[] = 
{
	GPIOCONFIG,
	ADCCONFIG,
	DACCONFIG,
	GPCONFIG,
	ADCCSEQUENCE,
};


SpiTest::SpiTest(unsigned nId, unsigned nSerialNum, std::string sName)
: m_nPortId(nId), m_sFirstName(sName), m_nCommProtocolSerialNum(nSerialNum)
{
}

SpiTest::~SpiTest()
{
}

void SpiTest::MakeWord(char *eightBits, unsigned short sixteenBits)
{
	eightBits[0] = sixteenBits >> 8;
	eightBits[1] = sixteenBits & 0x00FF;
}


unsigned int SpiTest::SpiInitializeSettings()
{
	if (!bcm2835_init())
		return -1;
	bcm2835_spi_begin();
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE1);
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_16);
	bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, low);
	
	for(int i=0; i<sizeof(config); i++)
	{
		makeWord(spiOut, config[j]);
		bcm2835_spi_transfern(spiOut, WORDSIZE);
	}
	return 1;
}

unsigned int SpiTest::TransferToSpi(unsigned short * pDacData, int nIndex)
{
	spiOut[0] = pDacData[nIndex] >> 8;
	spiOut[1] = pDacData[nIndex] & 0x0FF;
	bcm2835_spi_transfernb(spiOut, spiIn, WORDSIZE);
	
	return 1;
} 





















