#pragma once
#include "CSolidBody.h"

class CSphere final : public CSolidBody
{
public:
	CSphere(double density, double radius);
	double GetRadius() const;
	double GetVolume() const override;
private:
	void AppendProperties(std::ostream& strm, const std::string& spaces = "") const override;
	double m_radius;
};