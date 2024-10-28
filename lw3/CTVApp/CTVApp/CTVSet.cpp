#include "CTVSet.h"

void CTVSet::TurnOn()
{
	m_isOn = true;
}

void CTVSet::TurnOff()
{
	m_isOn = false;
}

bool CTVSet::SelectChannel(int channel)
{
	if ((m_isOn) && (channel >= 1) && (channel <= 99))
	{
		m_selectedChannel = channel;
		return true;
	}
	return false;
}

int CTVSet::GetChannel() const
{
	if (m_isOn)
		return m_selectedChannel;
	else
		return 0;
}

bool CTVSet::GetStatus() const
{
	return m_isOn;
}