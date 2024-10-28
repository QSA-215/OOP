#pragma once
#include "IPerson.h"

class IWorker : public IPerson
{
public:
	virtual void SetSpecialty(const std::string& specialty) = 0;
	virtual std::string GetSpecialty() const = 0;
};