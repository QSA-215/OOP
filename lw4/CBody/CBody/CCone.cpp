#include "CCone.h"

const double Pi = 3.14;

CCone::CCone(double density, double height, double baseRadius)
{
	SetDensity(density);
	SetType("Cone");
	m_height = height;
	m_baseRadius = baseRadius;
};

double CCone::GetBaseRadius() const
{
	return m_baseRadius;
};

double CCone::GetHeight() const
{
	return m_height;
};

double CCone::GetVolume() const
{
	return (Pi * m_baseRadius * m_baseRadius * m_height) / 3;
};

void CCone::AppendProperties(std::ostream& strm, const std::string& spaces) const
{
	strm << spaces << "  Base radius: " << GetBaseRadius() << std::endl
		<< spaces << "  Height: " << GetHeight() << std::endl;
};