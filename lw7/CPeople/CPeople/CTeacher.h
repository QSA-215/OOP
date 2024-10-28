#pragma once
#include "CPersonImpl.h"
#include "ITeacher.h"

class CTeacher : public CPersonImpl<ITeacher>
{
public:
	void SetSchoolSubject(const std::string& schoolSubject) override { m_schoolSubject = schoolSubject; };
	std::string GetSchoolSubject() const override { return m_schoolSubject; };
private:
	std::string m_schoolSubject;
};