#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "../CTV/CTVSet.h"
#include <iostream>

SCENARIO("test 1: turn on")
{
	CTVSet tv;
	tv.TurnOn();
	REQUIRE(tv.GetStatus() == true);
}

SCENARIO("test 2: turn off")
{
	CTVSet tv;
	tv.TurnOn();
	tv.TurnOff();
	REQUIRE(tv.GetStatus() == false);
}

SCENARIO("test 3: select channel")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(5);
	REQUIRE(tv.GetChannel() == 5);
}

SCENARIO("test 4: select wrong channel")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(100);
	REQUIRE(tv.GetChannel() == 1);
}

SCENARIO("test 5: select channel with TV off")
{
	CTVSet tv;
	tv.TurnOn();
	tv.TurnOff();
	tv.SelectChannel(5);
	REQUIRE(tv.GetChannel() == 1);
}

SCENARIO("test 6: save channel with TV off")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(5);
	tv.TurnOff();
	tv.TurnOn();
	REQUIRE(tv.GetChannel() == 5);
}