#include "CBody.h"

std::string CBody::GetType() const
{
	return m_type;
};

void CBody::SetType(std::string type)
{
	m_type = type;
};

void CBody::SetFather(const std::shared_ptr<CBody>& father)
{
	m_father = father;
};

std::shared_ptr<CBody> CBody::GetFather() const
{
	return m_father;
};

std::string CBody::ToString(const std::string& spaces) const
{
	std::ostringstream allInfo;
	allInfo << spaces << m_type << std::endl
		<< spaces << "  Density: " << std::to_string(GetDensity()) << std::endl
		<< spaces << "  Volume: " << std::to_string(GetVolume()) << std::endl
		<< spaces << "  Mass: " << std::to_string(GetMass()) << std::endl;
	AppendProperties(allInfo, spaces);
	return allInfo.str();
};