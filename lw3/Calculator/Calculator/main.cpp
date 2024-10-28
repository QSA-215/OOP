#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>

bool GoodIdentifier(const std::vector<std::string> commands)
{
	if (commands.size() < 2)
		return true;

	std::string identifier = commands[1];
	std::regex rgx("[_A-Za-z]\\w*");
	if (!std::regex_match(identifier, rgx))
		return false;

	/*if ((identifier[0] <= '9') && (identifier[0] >= '0'))
		return false;

	for (auto ch : identifier)
		if (((ch <= '9') && (ch >= '0')) || (ch == '_') || ((ch <= 'Z') && (ch >= 'A')) || ((ch <= 'z') && (ch >= 'a')))
		{
		}
		else
			return false;*/

	return true;
}

void LetVar(const std::string& identifier, const std::string& value, Calculator calc)
{
	if (!calc.IdentifierExists(identifier))
		calc.AddVar(identifier);

	if (calc.IdentifierExists(value))
		calc.LetVar(identifier, calc.FindValue(value));
	else
		calc.LetVar(identifier, std::stod(value));
}

void AddFn()
{
}

void PrintValue(const std::string& identifier, Calculator calc)
{
	std::cout << identifier << ": ";
	if (calc.FindValue(identifier) != std::nullopt)
		std::cout << calc.FindValue(identifier).value();
	else
		std::cout << "Nan";
	std::cout << std::endl;
}

void PrintValues(const std::vector<IdentifierPair>& pairs)
{
	for (const auto& pair : pairs)
	{
		std::cout << pair.identifier << ": ";
		if (pair.value != std::nullopt)
			std::cout << pair.value.value();
		else
			std::cout << "Nan";
		std::cout << std::endl;
	}
}

int main()
{
	Calculator calc;
	std::string line, command;
	std::istringstream lineStream(line);
	while (std::getline(std::cin, line))
	{
		lineStream.clear();
		lineStream.str(line);
		std::vector<std::string> commands;
		while (lineStream >> command)
			commands.push_back(command);

		if (!GoodIdentifier(commands))
		{
			std::cout << "error: Wrong identifier" << std::endl;
			continue;
		}

		if (commands[0] == "var")
		{
			if (!calc.AddVar(commands[1]))
				std::cout << "error: This identifier is already exist" << std::endl;
		}
		else if (commands[0] == "let")
			LetVar(commands[1], commands[3], calc);

		else if (commands[0] == "fn")
		{
			if (calc.IdentifierExists(commands[1]))
			{
				std::cout << "error: This identifier is already exist" << std::endl;
				continue;
			}
			
			if (commands.size() == 6)
				calc.AddFn(commands[1], commands[3], commands[4], commands[5]);
			else
				calc.AddFn(commands[1], commands[3]);
		}
		else if (commands[0] == "print")
			PrintValue(commands[1], calc);

		else if (commands[0] == "printvars")
			PrintValues(calc.GetVars());

		else if (commands[0] == "printfns")
			PrintValues(calc.GetFns());

		else
			std::cout << "error: Wrong input" << std::endl;

		commands.clear();
	}
	return 0;
}