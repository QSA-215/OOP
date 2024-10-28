#pragma once
#include "CBody.h"
#include <vector>
#include <memory>
// ������������ ����� ���� �������������, ���� ������ ����� �� ���
class CCompound final : public CBody, public std::enable_shared_from_this <CCompound>
{
public:
	CCompound();
	double GetDensity() const override;
	double GetVolume() const override;
	double GetMass() const override;
	bool AddChildBody(const std::shared_ptr<CBody>& child);
private:
	// ���� ��������� ������������!!!
	// ����� ��������� ���-�� � �������� - 
	// ���������� �� ����� ����� ���������, ���� �� nullptr,
	// ���� ��������� child, �� ���������� ����������
	// ���� ��� �� ���� �� �������� �������� ��������,
	// �� ���� ��� �������� ���� �������� � �������� ����
	void AppendProperties(std::ostream& strm, const std::string& spaces = "") const override;
	//std::shared_ptr<CCompound> m_father = nullptr;
	std::vector<std::shared_ptr<CBody>> m_compoundBody;
};