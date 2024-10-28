#pragma once

class CTVSet
{
private:
	bool isOn = false;
	int selectedChannel = 1;
public:
	void TurnOn();
	void TurnOff();
	bool SelectChannel(int channel);
	int GetChannel();
	bool GetStatus();
};