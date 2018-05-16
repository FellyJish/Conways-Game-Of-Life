#include "Config.h"
#include "CellAutomation.h"
#include <iostream>

unsigned const uSCREEN_WIDTH = 1024, uSCREEN_HEIGHT = 768, uQUAD_SIZE = 4, uFRAME_RATE = 60;

int main()
{
	Config config;
	char chOption;

	std::cout << "Would you like to use default config? Y/N: ";
	std::cin >> chOption;

	if (chOption == 'Y' || chOption == 'y')
	{	
		config.uScreenWidth = uSCREEN_WIDTH;
		config.uScreenHeight = uSCREEN_HEIGHT;
		config.uQuadSize = uQUAD_SIZE;
		config.uFrameRate = uFRAME_RATE;

		config.uSimWidth = config.uScreenWidth / config.uQuadSize;
		config.uSimHeight = config.uScreenHeight / config.uQuadSize;

		printf("Window width: %d\nWindow height: %d\nFramerate: %d\n", config.uScreenWidth, config.uScreenHeight, config.uFrameRate);
	}
	else if (chOption == 'N' || chOption == 'n')
	{
		std::cout << "Enter window width: ";
		std::cin >> config.uScreenWidth;

		std::cout << "Enter window height: ";
		std::cin >> config.uScreenHeight;

		std::cout << "Enter cell size (smaller numbers like 4-16 work better): ";
		std::cin >> config.uQuadSize;

		std::cout << "Enter max frame rate: ";
		std::cin >> config.uFrameRate;

		//Make it so that the cells fit in the window
		config.uScreenWidth -= config.uScreenWidth % config.uQuadSize;
		config.uScreenHeight -= config.uScreenHeight % config.uQuadSize;

		config.uSimWidth = config.uScreenWidth / config.uQuadSize;
		config.uSimHeight = config.uScreenHeight / config.uQuadSize;

		printf("Window width: %d\nWindow height: %d\nFramerate: %d\n", config.uScreenWidth, config.uScreenHeight, config.uFrameRate);
	}
	else
	{
		printf("Invalid input, using default config.\n");

		config.uScreenWidth = uSCREEN_WIDTH;
		config.uScreenHeight = uSCREEN_HEIGHT;
		config.uQuadSize = uQUAD_SIZE;
		config.uFrameRate = uFRAME_RATE;

		config.uSimWidth = config.uScreenWidth / config.uQuadSize;
		config.uSimHeight = config.uScreenHeight / config.uQuadSize;

		printf("Window width: %d\nWindow height: %d\nFramerate: %d\n", config.uScreenWidth, config.uScreenHeight, config.uFrameRate);
	}
	CellAutomation app(config);
	app.Run();
	return 0;
}
