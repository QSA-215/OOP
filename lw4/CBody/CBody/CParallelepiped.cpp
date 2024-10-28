#include "CParallelepiped.h"

CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
{
	SetDensity(density);
	SetType("Parallelepiped");
	m_width = width;
	m_height = height;
	m_depth = depth;
};
double CParallelepiped::GetWidth() const
{
	return m_width;
};

double CParallelepiped::GetHeight() const
{
	return m_height;
};

double CParallelepiped::GetDepth() const
{
	return m_depth;
};

double CParallelepiped::GetVolume() const
{
	return m_width * m_height * m_depth;
};

void CParallelepiped::AppendProperties(std::ostream& strm, const std::string& spaces) const
{
	strm << spaces << "  Width: " << GetWidth() << std::endl
		<< spaces << "  Height: " << GetHeight() << std::endl
		<< spaces << "  Depth: " << GetDepth() << std::endl;
};