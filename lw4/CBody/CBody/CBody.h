#pragma once
#include <string>
#include <sstream>

class CBody
{
public:
	std::string GetType() const;
	virtual double GetDensity() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetMass() const = 0;
	std::string ToString(const std::string& spaces = "") const;
	virtual void AppendProperties(std::ostream& strm, const std::string& spaces = "") const = 0;
	void SetFather(const std::shared_ptr<CBody>& father);//?
	std::shared_ptr<CBody> GetFather() const;//?
	virtual ~CBody() = default;
protected:
	void SetType(std::string type);
private:
	std::string m_type = "none";
	std::shared_ptr<CBody> m_father = nullptr;
};