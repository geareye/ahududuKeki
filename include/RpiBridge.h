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

class RpiBridge
{
	public:
		RpiBridge(unsigned nPortId, unsigned nSerialNum, std::string sName);
		~RpiBridge();


		// Function prototypes
		int BlinkPort(unsigned nDelay);
		int SetGpioValue(unsigned nPortId, unsigned nPortValue);
		int GetGpioValue(unsigned nPortId, unsigned *pnPortValue);

	protected:

	private:
		//member functions
                int map_peripheral(struct bcm2835_peripheral *p);
                void unmap_peripheral(struct bcm2835_peripheral *p);

                // I2C
                void dump_bsc_status();
                void wait_i2c_done();
                void i2c_init();
                // Priority
                int SetProgramPriority(int priorityLevel);

		//member variables
		unsigned			m_nPortId;
		std::string 		m_sFirstName;
		unsigned 			m_nCommProtocolSerialNum;

		bcm2835_peripheral gpio;// = {GPIO_BASE};
		bcm2835_peripheral bsc0;// = {BSC0_BASE};
};

