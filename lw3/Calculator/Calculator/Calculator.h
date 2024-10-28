#pragma once
#include <map>
#include <string>
#include <optional>
#include <vector>

enum class fnType {var, fn};

struct Function
{
	std::string identifier1;
	std::string action;
	std::string identifier2;
	fnType fnType;
};

// дать другое название
struct IdentifierPair
{
	std::string identifier;
	std::optional<double> value;
};

class Calculator
{
public:
	bool IdentifierExists(const std::string identifier) const;
	bool AddVar(const std::string& identifier);
	bool LetVar(
		const std::string& identifier, 
		const std::optional<double> value);

	bool AddFn(
		const std::string& identifier, 
		const std::string& operator1, 
		const std::string& operation = "", 
		const std::string& operator2 = "");

	std::optional<double> FindValue(const std::string& identifier) const;
	std::vector<IdentifierPair> GetVars() const;
	std::vector<IdentifierPair> GetFns() const;
private:
	std::optional<double> Addition(
		const std::string& identifier1, 
		const std::string& identifier2) const;

	std::optional<double> Subtraction(
		const std::string& identifier1, 
		const std::string& identifier2) const;

	std::optional<double> Multiplication(
		const std::string& identifier1, 
		const std::string& identifier2) const;

	std::optional<double> Division(
		const std::string& identifier1, 
		const std::string& identifier2) const;
		// double может быть NAN
	std::map<std::string, std::optional<double>> m_vars;
	std::map<std::string, Function> m_fns;
};