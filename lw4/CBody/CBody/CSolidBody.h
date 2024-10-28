#pragma once
#include "CBody.h"

class CSolidBody : public CBody
{
public:
	void SetDensity(const double density);
	double GetDensity() const final;
	double GetMass() const final;
private:
	double m_density = 0;
};