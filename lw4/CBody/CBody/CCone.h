#pragma once
#include "CSolidBody.h"

class CCone final : public CSolidBody
{
public:
	CCone(double density, double height, double baseRadius);
	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
private:
	void AppendProperties(std::ostream& strm, const std::string& spaces = "") const override;
	double m_baseRadius;
	double m_height;
};