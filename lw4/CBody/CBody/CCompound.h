#pragma once
#include "CBody.h"
#include <vector>
#include <memory>
// зацикливание может быть теоретическим, надо просто тесты на это
class CCompound final : public CBody, public std::enable_shared_from_this <CCompound>
{
public:
	CCompound();
	double GetDensity() const override;
	double GetVolume() const override;
	double GetMass() const override;
	bool AddChildBody(const std::shared_ptr<CBody>& child);
private:
	// Ќјƒќ ѕ–ќ¬≈–»“№ ѕ–ј¬»Ћ№Ќќ—“№!!!
	// когда добавл€ем что-то в компаунд - 
	// проходимс€ по отцам этого компаунда, пока на nullptr,
	// если встречаем child, то выкидываем исключение
	// если нет то если мы пытаемс€ добавить компаунд,
	// то надо ему добавить этот компаунд в качестве отца
	void AppendProperties(std::ostream& strm, const std::string& spaces = "") const override;
	//std::shared_ptr<CCompound> m_father = nullptr;
	std::vector<std::shared_ptr<CBody>> m_compoundBody;
};