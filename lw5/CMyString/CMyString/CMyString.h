#pragma once
#include <iostream>
#include <string>

class CMyString
{
public:
    CMyString();
    CMyString(const char* pString);
    CMyString(const char* pString, size_t length);
    CMyString(CMyString const& other);
    CMyString(CMyString&& other) noexcept;
    CMyString(std::string const& stlString);
    ~CMyString() = default;

    char* GetStringData() const;
    size_t GetLength() const;
    size_t GetCapacity() const;

    void Clear();
    CMyString SubString(size_t start, size_t length = SIZE_MAX) const;

    CMyString& operator=(const CMyString& other);
    friend CMyString operator+(const CMyString& left, const CMyString& right);
    //CMyString& operator+(const CMyString& other);
    CMyString& operator+=(const CMyString& other);

    bool operator==(const CMyString& other) const;
    bool operator!=(const CMyString& other) const;
    bool operator<(const CMyString& other) const;
    bool operator>(const CMyString& other) const;
    bool operator<=(const CMyString& other) const;
    bool operator>=(const CMyString& other) const;

    const char& operator[](size_t index) const;
    char& operator[](size_t index);


    typedef char* iterator;
    typedef const char* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
private:
    char* m_string;
    size_t m_length;
    size_t m_capacity;
};

std::ostream& operator<<(std::ostream& out, const CMyString& str);
std::istream& operator>>(std::istream& in, CMyString& str);