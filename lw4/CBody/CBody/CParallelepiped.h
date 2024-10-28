#pragma once
#include "CSolidBody.h"

class CParallelepiped final : public CSolidBody
{
public:
	CParallelepiped(double density, double width, double height, double depth);
	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	double GetVolume() const override;
private:
	void AppendProperties(std::ostream& strm, const std::string& spaces = "") const override;
	double m_width;
	double m_height;
	double m_depth;
};