#pragma once
#include "CStudentImpl.h"
#include "IAdvancedStudent.h"

class CAdvancedStudent : public CStudentImpl<IAdvancedStudent>
{
public:
	void SetDissertationTopic(const std::string& dissertationTopic) override { m_dissertationTopic = dissertationTopic; };
	std::string GetDissertationTopic() const override { return m_dissertationTopic; };
private:
	std::string m_dissertationTopic;
};