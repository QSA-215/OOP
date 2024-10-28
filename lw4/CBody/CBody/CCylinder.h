#pragma once
#include "CSolidBody.h"

class CCylinder final : public CSolidBody
{
public:
	CCylinder(double density, double height, double baseRadius);
	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
private:
	void AppendProperties(std::ostream& strm, const std::string& spaces = "") const override;
	double m_baseRadius;
	double m_height;
};