#pragma once

class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	bool SelectChannel(int channel);
	int GetChannel() const;
	bool GetStatus() const;
private:
	bool m_isOn = false;
	int m_selectedChannel = 1;
};