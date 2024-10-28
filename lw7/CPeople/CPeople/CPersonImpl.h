#pragma once
#include <string>

template <typename Base>
class CPersonImpl : public Base
{
public:
	void SetFirstName(const std::string& firstName) override { m_firstName = firstName; };
	std::string GetFirstName() const override { return m_firstName; };

	void SetMiddleName(const std::string& midlleName) override { m_middleName = midlleName; };
	std::string GetMiddleName() const override { return m_middleName; };

	void SetLastName(const std::string& lastName) { m_lastName = lastName; };
	std::string GetLastName() const override { return m_lastName; };

	void SetAddress(const std::string& address) override { m_address = address; };
	std::string GetAddress() const override { return m_address; };
private:
	std::string m_firstName;
	std::string m_middleName;
	std::string m_lastName;
	std::string m_address;
};