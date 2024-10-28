#pragma once
#include "CPersonImpl.h"

template <typename Base>
class CStudentImpl : public CPersonImpl<Base>
{
public:
	void SetUniversityName(const std::string& universityName) override { m_universityName = universityName; };
	std::string GetUniversityName() const override { return m_universityName; };

	void SetStudentID(const std::string& studentID) override { m_studentID = studentID; };
	std::string GetStudentID() const override { return m_studentID; };
private:
	std::string m_universityName;
	std::string m_studentID;
};