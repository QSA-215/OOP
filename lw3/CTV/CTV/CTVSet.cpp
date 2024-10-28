#include "CTVSet.h"

void CTVSet::TurnOn()
{
	isOn = true;
}

void CTVSet::TurnOff()
{
	isOn = false;
}

bool CTVSet::SelectChannel(int channel)
{
	if ((isOn) && (channel >= 1) && (channel <= 99))
	{
		selectedChannel = channel;
		return true;
	}
	return false;
}

int CTVSet::GetChannel()
{
	return selectedChannel;
}

bool CTVSet::GetStatus()
{
	return isOn;
}