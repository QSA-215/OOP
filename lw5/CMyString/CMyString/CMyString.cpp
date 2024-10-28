#include "CMyString.h"

char* Copy(const char* pString, size_t length)
{
	char* data = new char[length + 1];
	memcpy(data, pString, length);
	data[length] = '\0';
	return data;
};

CMyString::CMyString()
{
	m_string = new char[1]();
	m_length = 0;
	m_capacity = 0;
};

CMyString::CMyString(const char* pString)
{
	m_length = strlen(pString);
	m_string = Copy(pString, m_length);
	m_capacity = m_length;
};

CMyString::CMyString(const char* pString, size_t length)
{
	m_length = length;
	m_string = Copy(pString, m_length);
	m_capacity = m_length;
};

CMyString::CMyString(std::string const& stlString)
{
	m_length = stlString.size();
	m_string = Copy(stlString.c_str(), m_length);
	m_capacity = m_length;
};

CMyString::CMyString(CMyString const& other)
{
	m_string = other.m_string;
	m_length = other.m_length;
	m_capacity = other.m_capacity;
};

CMyString::CMyString(CMyString&& other) noexcept
{
	//m_string = std::move(other.GetStringData());
	//m_length = std::move(other.GetLength());
	//m_capacity = std::move(other.GetCapacity());
	m_string = other.m_string;
	m_length = other.m_length;
	m_capacity = other.m_capacity;
	other.m_string = nullptr;
	other.m_length = 0;
	other.m_capacity = 0;
};

char* CMyString::GetStringData() const
{
	return m_string;
};

size_t CMyString::GetLength() const
{
	return m_length;
};

size_t CMyString::GetCapacity() const
{
	return m_capacity;
};

void CMyString::Clear()
{
	delete[] m_string;
	m_string = new char[1]();
	m_length = 0;
	m_capacity = 0;
};

CMyString CMyString::SubString(size_t start, size_t length) const
{
	if (start >= m_length)
		throw "Wrong index of string";
	else if (start < 0 || length < 0)
		throw "Argument out of range";
	if (start + length >= m_length)
		return CMyString(m_string + start, m_length - start);
	else
		return CMyString(m_string + start, length);
};

CMyString& CMyString::operator=(const CMyString& other)
{
	if (std::addressof(other) != this)
	{
		CMyString tmpCopy(other);
		std::swap(m_string, tmpCopy.m_string);
		std::swap(m_length, tmpCopy.m_length);
		std::swap(m_capacity, tmpCopy.m_capacity);
	}
	return *this;
};

CMyString& CMyString::operator+=(const CMyString& other)
{
	{
		size_t newLength = m_length + other.m_length;
		size_t newCapacity = (m_capacity + other.m_capacity) * 2;
		char* newData = new char[newLength + 1];

		memcpy(newData, m_string, m_length);
		memcpy(newData + m_length, other.m_string, other.m_length);
		newData[newLength] = '\0';

		std::swap(m_string, newData);
		std::swap(m_length, newLength);
		std::swap(m_capacity, newCapacity);
	}
	return *this;
};

CMyString operator+(const CMyString& left, const CMyString& right)
{
	CMyString result(left);
	result += right;
	return result;
};

bool CMyString::operator==(const CMyString& other) const
{
	if (m_length != other.m_length)
		return false;

	for (size_t i = 0; i < m_length; ++i)
		if (m_string[i] != other.m_string[i])
			return false;

	return true;
};

bool CMyString::operator!=(const CMyString& other) const
{
	return !(*this == other);
};

bool CMyString::operator<(const CMyString& other) const
{
	if (m_length != other.m_length)
		return m_length < other.m_length;

	for (size_t i = 0; i < m_length; ++i)
		if (m_string[i] < other.m_string[i])
			return true;
		else if (m_string[i] > other.m_string[i])
			return false;

	return false;
};

bool CMyString::operator>(const CMyString& other) const
{
	return other < *this;
};

bool CMyString::operator<=(const CMyString& other) const
{
	return !(*this > other);
};

bool CMyString::operator>=(const CMyString& other) const
{
	return !(*this < other);
};

char& CMyString::operator[](size_t index)
{
	if ((index < 0) || (m_length < index))
		throw "Wrong index of string";
	return m_string[index];
};

const char& CMyString::operator[](size_t index) const
{
	if ((index < 0) || (m_length < index))
		throw "Wrong index of string";
	return m_string[index];
};

std::ostream& operator<<(std::ostream& out, const CMyString& str)
{
	out << str.GetStringData();
	return out;
};

std::istream& operator>>(std::istream& in, CMyString& str)
{
	std::string tempStr;
	in >> tempStr;
	str = CMyString(tempStr);
	return in;
};

CMyString::iterator CMyString::begin()
{
	return m_string;
};

CMyString::iterator CMyString::end()
{
	return m_string + m_length;
};

CMyString::const_iterator CMyString::begin() const
{
	return m_string;
};

CMyString::const_iterator CMyString::end() const
{
	return m_string + m_length;
};

CMyString::reverse_iterator CMyString::rbegin()
{
	return std::reverse_iterator<char*>(end());
};

CMyString::reverse_iterator CMyString::rend()
{
	return std::reverse_iterator<char*>(begin());
};

CMyString::const_reverse_iterator CMyString::crbegin() const
{
	return std::reverse_iterator<const char*>(end());
};

CMyString::const_reverse_iterator CMyString::crend() const
{
	return std::reverse_iterator<const char*>(begin());
};