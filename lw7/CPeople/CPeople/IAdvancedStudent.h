#pragma once
#include "IStudent.h"

class IAdvancedStudent : IStudent
{
public:
	virtual void SetDissertationTopic(const std::string& dissertationTopic) = 0;
	virtual std::string GetDissertationTopic() const = 0;
};