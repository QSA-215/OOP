#pragma once
#include <string>

class IPerson
{
public:
    virtual std::string GetFirstName() const = 0;
    virtual void SetFirstName(const std::string& firstName) = 0;

    virtual std::string GetLastName() const = 0;
    virtual void SetLastName(const std::string& lastName) = 0;

    virtual std::string GetMiddleName() const = 0;
    virtual void SetMiddleName(const std::string& middleName) = 0;

    virtual std::string GetAddress() const = 0;
    virtual void SetAddress(const std::string& address) = 0;
};