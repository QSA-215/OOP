#include "Calculator.h"
#include <iostream>
#include <iomanip>

bool Calculator::IdentifierExists(const std::string identifier) const
{
	if ((m_vars.find(identifier) == m_vars.end()) && (m_fns.find(identifier) == m_fns.end()))
		return false;
	else
		return true;
};

bool Calculator::AddVar(const std::string& identifier)
{
	if (IdentifierExists(identifier))
		return false;

	m_vars[identifier] = std::nullopt;
	return true;
};

bool Calculator::LetVar(const std::string& identifier, std::optional<double> value)
{
	if (!IdentifierExists(identifier))
		return false;

	m_vars[identifier] = value;
	return true;
};

bool Calculator::AddFn(const std::string& identifier, const std::string& operator1, const std::string& operation, const std::string& operator2)
{
	if (IdentifierExists(identifier))
		return false;

	if ((operation != "+") && (operation != "-") && (operation != "*") && (operation != "/") && (operation != ""))
		return false;

	Function fn;
	fn.identifier1 = operator1;
	fn.action = operation;
	fn.identifier2 = operator2;

	if (operator2 != "")
		fn.fnType = fnType::fn;
	else
		fn.fnType = fnType::var;

	m_fns[identifier] = fn;
	return true;
};

// ответ на "нет такой переменной" и "переменная равна nullopt" будут одинаковые
std::optional<double> Calculator::FindValue(const std::string& identifier) const
{
	if (!IdentifierExists(identifier))
		return std::nullopt;
	
	if (m_vars.find(identifier) != m_vars.end())
		return m_vars.at(identifier);
	
	if (m_fns.at(identifier).fnType == fnType::var)
		return FindValue(m_fns.at(identifier).identifier1);
		
	if (m_fns.at(identifier).action == "+")
		return Addition(m_fns.at(identifier).identifier1, m_fns.at(identifier).identifier2);
	else if (m_fns.at(identifier).action == "-")
		return Subtraction(m_fns.at(identifier).identifier1, m_fns.at(identifier).identifier2);
	else if (m_fns.at(identifier).action == "*")
		return Multiplication(m_fns.at(identifier).identifier1, m_fns.at(identifier).identifier2);
	else if (m_fns.at(identifier).action == "/")
		return Division(m_fns.at(identifier).identifier1, m_fns.at(identifier).identifier2);
	else
		return std::nullopt;
};

std::optional<double> Calculator::Addition(const std::string& identifier1, const std::string& identifier2) const
{
	std::optional<double> value1 = FindValue(identifier1);
	std::optional<double> value2 = FindValue(identifier2);

	if ((value1 != std::nullopt) && (value2 != std::nullopt))
		return value1.value() + value2.value();
	else
		return std::nullopt;
	
};

std::optional<double> Calculator::Subtraction(const std::string& identifier1, const std::string& identifier2) const
{
	std::optional<double> value1 = FindValue(identifier1);
	std::optional<double> value2 = FindValue(identifier2);

	if ((value1 != std::nullopt) && (value2 != std::nullopt))
		return value1.value() - value2.value();
	else
		return std::nullopt;
};

std::optional<double> Calculator::Multiplication(const std::string& identifier1, const std::string& identifier2) const
{
	std::optional<double> value1 = FindValue(identifier1);
	std::optional<double> value2 = FindValue(identifier2);

	if ((value1 != std::nullopt) && (value2 != std::nullopt))
		return value1.value() * value2.value();
	else
		return std::nullopt;
};

std::optional<double> Calculator::Division(const std::string& identifier1, const std::string& identifier2) const
{
	std::optional<double> value1 = FindValue(identifier1);
	std::optional<double> value2 = FindValue(identifier2);

	if ((value1 != std::nullopt) && (value2 != std::nullopt))
		return value1.value() / value2.value();
	else
		return std::nullopt;
};

std::vector<IdentifierPair> Calculator::GetVars() const
{
	std::vector<IdentifierPair> varPairs;
	for (const auto& var : m_vars)
	{
		IdentifierPair varPair;
		varPair.identifier = var.first;
		varPair.value = var.second;
		varPairs.push_back(varPair);
	}
	return varPairs;
};

std::vector<IdentifierPair> Calculator::GetFns() const
{
	std::vector<IdentifierPair> fnPairs;
	for (const auto& fn : m_fns)
	{
		IdentifierPair fnPair;
		fnPair.identifier = fn.first;
		fnPair.value = FindValue(fn.first);
		fnPairs.push_back(fnPair);
	}
	return fnPairs;
};