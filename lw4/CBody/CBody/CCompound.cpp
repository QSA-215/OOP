#include "CCompound.h"

CCompound::CCompound()
{
	SetType("Compound");
};

double CCompound::GetDensity() const
{
	if (m_compoundBody.empty())
		return NAN;

	return GetMass() / GetVolume();
};

double CCompound::GetVolume() const
{
	if (m_compoundBody.empty())
		return NAN;

	double totalVolume = 0;
	for (const auto& body : m_compoundBody)
		totalVolume += body->GetVolume();
	return totalVolume;
};

double CCompound::GetMass() const
{
	if (m_compoundBody.empty())
		return NAN;

	double totalMass = 0;
	for (const auto& body : m_compoundBody)
		totalMass += body->GetVolume() * body->GetDensity();
	return totalMass;
};

// ÍÀÄÎ ÏĞÎÂÅĞÈÒÜ ÏĞÀÂÈËÜÍÎÑÒÜ!!!
bool CCompound::AddChildBody(const std::shared_ptr<CBody>& child)
{
	//std::shared_ptr<CCompound> father = m_father;
	std::shared_ptr<CBody> father = GetFather();
	while (father != nullptr)
	{
		if (father == child)
			return false;
		father = father->GetFather();
		//father = dynamic_cast<std::shared_ptr<CCompound>*>(father->GetFather());//???
	}
	if (child->GetType() == "Compound")
		child->SetFather(shared_from_this());
	//CCompound temp(m_compoundBody);
	m_compoundBody.push_back(child);
	return true;
};

void CCompound::AppendProperties(std::ostream& strm, const std::string& spaces) const
{
	strm << spaces << "{" << std::endl;
	for (const auto& body : m_compoundBody)
		strm << body->ToString(spaces + "  ");
	strm << spaces << "}" << std::endl;
};