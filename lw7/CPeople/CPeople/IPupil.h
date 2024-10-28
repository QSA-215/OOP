#pragma once
#include "IPerson.h"

class IPupil : public IPerson
{
public:
	virtual void SetSchoolName(const std::string& schoolName) = 0;
	virtual std::string GetSchoolName() const = 0;

	virtual void SetGrade(const std::string& grade) = 0;
	virtual std::string GetGrade() const = 0;
};