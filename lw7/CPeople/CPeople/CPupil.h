#pragma once
#include "CPersonImpl.h"
#include "IPupil.h"

class CPupil: public CPersonImpl<IPupil>
{
public:
	void SetSchoolName(const std::string& schoolName) override { m_schoolName = schoolName; };
	std::string GetSchoolName() const override { return m_schoolName; };

	void SetGrade(const std::string& grade) override { m_grade = grade; };
	std::string GetGrade() const override { return m_grade; };
private:
	std::string m_schoolName;
	std::string m_grade;
};