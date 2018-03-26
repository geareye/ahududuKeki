#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <assert.h>

#include <sched.h>		// To set the priority on linux

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>

//all of the #defines are going the header below.
#include "rpi_definitions.h"
#include "RpiCommands.h"

// IO Acces
struct bcm2835_peripheral {
    unsigned long addr_p;
    int mem_fd;
    void *map;
    volatile unsigned int *addr;
};

class SpiTest
{
public:
	SpiTest(unsigned nPortId, unsigned nSerialNum, std::string sName);
	~SpiTest();
	
	void 		 MakeWord(char *eightBits, unsigned short sixteenBits);
	unsigned int SpiInitializeSettings();
	unsigned int TransferToSpi(unsigned short * pDacData, int nIndex);

protected:

private:
	bcm2835_peripheral gpio;// = {GPIO_BASE};
	bcm2835_peripheral bsc0;// = {BSC0_BASE};
	
	char spiOut[2];
	char spiIn[2];
};

