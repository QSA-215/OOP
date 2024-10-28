#pragma once
#include "IPerson.h"

class ITeacher : IPerson
{
public:
	virtual void SetSchoolSubject(const std::string& schoolSubject) = 0;
	virtual std::string GetSchoolSubject() const = 0;
};