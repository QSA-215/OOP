#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include "CFigures.h"
// надо табул€цию после вывода compound
std::shared_ptr<CBody> GetMostMassBody(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	std::shared_ptr<CBody> mostMassBody = bodies[0];
	for (const auto& body : bodies)
		if (body->GetMass() > mostMassBody->GetMass())
			mostMassBody = body;
	return mostMassBody;
};

std::shared_ptr<CBody> GetLeastMassBodyInWater(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	const double WaterDensity = 1000;

	std::shared_ptr<CBody> LessMassBodyInWater = bodies[0];
	for (const auto& body : bodies)
		if (((body->GetDensity() - WaterDensity) * body->GetVolume()) < 
			((LessMassBodyInWater->GetDensity() - WaterDensity) * LessMassBodyInWater->GetVolume()))
			LessMassBodyInWater = body;

	return LessMassBodyInWater;
};

void GetInfo(const std::vector<std::shared_ptr<CBody>>& bodies)
{
	for (const auto& body : bodies)
		std::cout << body->ToString() << std::endl;
};

std::shared_ptr<CBody> AddSimpleBody(std::istringstream& lineStream, const std::string& command)
{
	if (command == "cone")
	{
		double density, height, baseRadius;
		lineStream >> density >> height >> baseRadius;
		return std::make_shared<CCone>(CCone(density, height, baseRadius));
	}
	else if (command == "cylinder")
	{
		double density, height, baseRadius;
		lineStream >> density >> height >> baseRadius;
		return std::make_shared<CCylinder>(CCylinder(density, height, baseRadius));
	}
	else if (command == "parallelepiped")
	{
		double density, width, height, depth;
		lineStream >> density >> width >> height >> depth;
		return std::make_shared<CParallelepiped>(CParallelepiped(density, width, height, depth));
	}
	else if (command == "sphere")
	{
		double density, radius;
		lineStream >> density >> radius;
		return std::make_shared<CSphere>(CSphere(density, radius));
	}
};

std::shared_ptr<CBody> AddCompoundBody(std::istream& input)
{
	CCompound compoundBody;
	std::string line, command;
	std::istringstream lineStream(line);
	std::getline(input, line);
	while (std::getline(input, line))
	{
		lineStream.clear();
		lineStream.str(line);
		lineStream >> command;
		if (command == "compound")
		{
			compoundBody.AddChildBody(AddCompoundBody(std::cin));
		}
		else if ((command == "cone") || (command == "cylinder") ||
			(command == "parallelepiped") || (command == "sphere"))
		{
			compoundBody.AddChildBody(AddSimpleBody(lineStream, command));
		}
		else if (command == "}")
		{
			return std::make_shared<CCompound>(compoundBody);
		}
		else
		{
			std::cout << "error" << std::endl;
		}
		command = "";
	}
};

int main()
{
	std::vector<std::shared_ptr<CBody>> bodies;
	std::string line, command;
	std::istringstream lineStream(line);

	while (std::getline(std::cin, line))
	{
		lineStream.clear();
		lineStream.str(line);
		lineStream >> command;
		if (command == "compound")
		{
			bodies.push_back(AddCompoundBody(std::cin));
		}
		else if ((command == "cone") || (command == "cylinder") ||
			(command == "parallelepiped") || (command == "sphere"))
		{
			bodies.push_back(AddSimpleBody(lineStream, command));
		}
		else
		{
			std::cout << "error" << std::endl;
		}
		command = "";
	}
	if (bodies.empty())
		return 0;

	GetInfo(bodies);
	std::cout << "The body with the highest mass is:" << std::endl << GetMostMassBody(bodies)->ToString() << std::endl;
	std::cout << "The body that will weigh the least when completely submerged in water:" 
		<< std::endl << GetLeastMassBodyInWater(bodies)->ToString() << std::endl;

	return 0;
}