#include <stdio.h>
#include <iostream>
#include "RpiBridge.h"

#include "rpi_status.h"

using namespace std;

int main(int argc, char *argv[])
{
	unsigned nDelayInSeconds = 1;
  	unsigned nPortId = 17;//0xB000B1E5;
  	unsigned nSerialNum = 0x12345678;//DEADBEEF;
	unsigned nPortValue;
  	string sName = "test";
	RpiBridge rpiBridge(nPortId, nSerialNum, sName);

	unsigned nCommandInput;
	//nUnsignedPortId = (unsigned) atoi(argv[1]);

	Status s = Pending;
	s = Approved;

	while (nCommandInput != RETURN_FAILURE)
	{
		printf("Enter the command:\n ");//as always ask the user for needed info
		scanf("%x",&nCommandInput);
		cout << "supplied : " << nCommandInput << endl;

		//currently the way called is bad, it could rely on member variable initialized during class calling
		if (nCommandInput == PIN_VALUE_OFF)
			rpiBridge.SetGpioValue(nPortId, PIN_VALUE_OFF);
		if (nCommandInput == PIN_VALUE_ON)
			rpiBridge.SetGpioValue(nPortId, PIN_VALUE_ON);
	}


//	rpiBridge.BlinkPort(nDelayInSeconds);

	return 0;
}

#if 0
while (nUnsignedPortId != 99)
	{
		printf("Enter the GPIO number:\n ");//as always ask the user for needed info
		scanf("%u",&nUnsignedPortId);
		cout << "Port ID supplied : " << nUnsignedPortId << endl;


		rpiBridge.SetGpioValue(nUnsignedPortId, PIN_VALUE_ON);
		rpiBridge.GetGpioValue(nUnsignedPortId,&nPortValue);
		cout << "port value when on: " <<endl;
		printf("0x%.8X \n", nPortValue);

		sleep(1);

	        rpiBridge.SetGpioValue(nUnsignedPortId, PIN_VALUE_OFF);
	        rpiBridge.GetGpioValue(nUnsignedPortId,&nPortValue);
	        cout << "port value when off: " <<endl;
	        printf("0x%.8X\n", nPortValue);
	}

#endif

