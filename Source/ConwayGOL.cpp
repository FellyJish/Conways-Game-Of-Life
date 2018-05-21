#include "Config.h"
#include "CellAutomation.h"
#include <iostream>

unsigned const uSCREEN_WIDTH = 800, uSCREEN_HEIGHT = 600, uQUAD_SIZE = 3, uFRAME_RATE = 60;

int main()
{
	Config config;
	char chOption;

	std::cout << "Hello my lovely, lucious, leggy lesbian named: LUCY\n";
	std::cout << "This is called Conway's game of life. It kinda simulates what bacteria etc do.\n";
	std::cout << "It can make some funky ass patterns\n";
	std::cout << "When prompted, type y or n, and then hit enter.\n";
	std::cout << "(if you type something else in it MIGHT break as I've not fully accounted for that so DON'T BE A DICK PLEZ <3)\n";
	std::cout << "--------------------------------------------------------------------------------------------------------------\n\n";
	std::cout << "Would you like to use default setup? Y/N: ";
	std::cin >> chOption;

	if (chOption == 'Y' || chOption == 'y')
	{
		config.uScreenWidth = uSCREEN_WIDTH;
		config.uScreenHeight = uSCREEN_HEIGHT;
		config.uQuadSize = uQUAD_SIZE;
		config.uFrameRate = uFRAME_RATE;

		config.uSimWidth = config.uScreenWidth / config.uQuadSize;
		config.uSimHeight = config.uScreenHeight / config.uQuadSize;

		printf("Window width: %d\nWindow height: %d\nFramerate: %d\nCell size %d\n", config.uScreenWidth, config.uScreenHeight, config.uFrameRate, uQUAD_SIZE);
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
