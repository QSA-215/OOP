#include "CTV.h"

void DrawTV(const int& channel = 0)
{
	system("cls");
	if (channel == 0)
		std::cout << TV_OFF;
	else
	{
		if (channel - 9 <= 0)
			std::cout << TV_TOP << '0' << channel;
		else
			std::cout << TV_TOP << channel;

		if (channel == 1)
			std::cout << TV_BOTTOM_1;
		else if (channel == 5)
			std::cout << TV_BOTTOM_5;
		else if (channel == 6)
			std::cout << TV_BOTTOM_6;
		else if (channel == 7)
			std::cout << TV_BOTTOM_7;
		else if (channel == 69)
			std::cout << TV_BOTTOM_69;
		else
			std::cout << TV_BOTTOM;
	}
}

void ProcessCommand(CTVSet& tv, const std::string& command)
{
	if (command == "TurnOn")
	{
		tv.TurnOn();
		DrawTV(tv.GetChannel());
	}

	else if (command == "TurnOff")
	{
		tv.TurnOff();
		DrawTV();
	}

	else if (command == "SelectChannel")
	{
		if (tv.GetStatus())
		{
			int channel;
			std::cout << "> ";
			std::cin >> channel;
			tv.SelectChannel(channel);
			DrawTV(tv.GetChannel());
		}
		else
			std::cout << "TV is off" << std::endl;
	}

	else if (command == "Info")
	{
		if (tv.GetStatus())
			std::cout << "TV is on" << std::endl;
		else
			std::cout << "TV is off" << std::endl;

		std::cout << "Selected channel is " << tv.GetChannel() << std::endl;
	}

	else
		std::cout << "Wrong input." << std::endl;
}

void RunCTV()
{
	CTVSet tv;
	DrawTV();
	std::string command;
	while (true)
	{
		std::cout << "> ";
		std::cin >> command;
		ProcessCommand(tv, command);
	}
}