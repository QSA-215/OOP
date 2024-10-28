#include <iostream>
#include <string>
#include "CTVSet.h"
#include "CTV.h"

const std::string TV_TOP = "\t       \\  /      \n"
"\t _______\\/_______\n"
"\t|";
const std::string TV_BOTTOM = "              |\n"
"\t| * * *  * * * * |\n"
"\t| * No signal  * |\n"
"\t| * * *  * * * * |\n"
"\t|________________|\n"
"\t    ^        ^    \n";

const std::string TV_OFF = "\t       \\  /      \n"
"\t _______\\/_______\n"
"\t|                |\n"
"\t|                |\n"
"\t|       TV       |\n"
"\t|                |\n"
"\t|________________|\n"
"\t    ^        ^    \n";

const std::string TV_BOTTOM_1 = "              |\n"
"\t|    HOBOCTN     |\n"
"\t|      CBO       |\n"
"\t|                |\n"
"\t|________________|\n"
"\t    ^        ^    \n";

const std::string TV_BOTTOM_5 = " PEH-TB       |\n"
"\t|                |\n"
"\t|     ALIENS     |\n"
"\t|                |\n"
"\t|________________|\n"
"\t    ^        ^    \n";

const std::string TV_BOTTOM_6 = " CTC          |\n"
"\t| XAXAXA         |\n"
"\t|     XAXAXA     |\n"
"\t|         XAXAXA |\n"
"\t|________________|\n"
"\t    ^        ^    \n";

const std::string TV_BOTTOM_7 = " THT          |\n"
"\t|                |\n"
"\t|   COMEDY       |\n"
"\t|       CLUB     |\n"
"\t|________________|\n"
"\t    ^        ^    \n";

const std::string TV_BOTTOM_69 = "              |\n"
"\t|   XXX          |\n"
"\t|       18+      |\n"
"\t|          HOT   |\n"
"\t|________________|\n"
"\t    ^        ^    \n";

void DrawTV(const int channel = 0)
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