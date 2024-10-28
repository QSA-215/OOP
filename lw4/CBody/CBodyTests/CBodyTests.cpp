#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "../CBody/CFigures.h"
#include <iostream>
#include <memory>
#include <numeric>

const double eps = 1e-6;

SCENARIO("test 1: test sphere")
{
	CSphere sphere(2, 5);
	REQUIRE(sphere.GetRadius() == 5);
	REQUIRE(sphere.GetDensity() == 2);
	REQUIRE(sphere.GetVolume() - 523.333333 < eps);
	REQUIRE(sphere.GetMass() - 1046.666666 < eps);
}

SCENARIO("test 2: test cone")
{
	CCone cone(2, 5, 5);
	REQUIRE(cone.GetBaseRadius() == 5);
	REQUIRE(cone.GetHeight() == 5);
	REQUIRE(cone.GetDensity() == 2);
	REQUIRE(cone.GetVolume() - 130.833333 < eps);
	REQUIRE(cone.GetMass() - 261.666666 < eps);
}

SCENARIO("test 3: test cylinder")
{
	CCylinder cylinder(2, 5, 5);
	REQUIRE(cylinder.GetBaseRadius() == 5);
	REQUIRE(cylinder.GetHeight() == 5);
	REQUIRE(cylinder.GetDensity() == 2);
	REQUIRE(cylinder.GetVolume() - 392.5 < eps);
	REQUIRE(cylinder.GetMass() - 785 < eps);
}

SCENARIO("test 4: test parallelepiped")
{
	CParallelepiped parallelepiped(2, 5, 5, 5);
	REQUIRE(parallelepiped.GetWidth() == 5);
	REQUIRE(parallelepiped.GetHeight() == 5);
	REQUIRE(parallelepiped.GetDepth() == 5);
	REQUIRE(parallelepiped.GetDensity() == 2);
	REQUIRE(parallelepiped.GetVolume() - 125 < eps);
	REQUIRE(parallelepiped.GetMass() - 250 < eps);
}

SCENARIO("test 5: test compound")
{
	CCompound compoundBody;
	compoundBody.AddChildBody(std::make_shared<CSphere>(CSphere(2, 5)));
	compoundBody.AddChildBody(std::make_shared<CSphere>(CSphere(1, 5)));
	REQUIRE(compoundBody.GetDensity() == 1.5);
	REQUIRE(compoundBody.GetVolume() - 1046.666666 < eps);
	REQUIRE(compoundBody.GetMass() - 1570 < eps);
}

SCENARIO("test 6: sphere ToString test")
{
	std::string allInfo = "Sphere\n  Density: 2.000000\n  Volume: 523.333333\n  Mass: 1046.666667\n  Radius: 5\n";
	CSphere sphere(2, 5);
	REQUIRE(sphere.ToString() == allInfo);
}

SCENARIO("test 7: cone ToString test")
{
	std::string allInfo = "Cone\n  Density: 2.000000\n  Volume: 130.833333\n  Mass: 261.666667\n  Base radius: 5\n  Height: 5\n";
	CCone cone(2, 5, 5);
	REQUIRE(cone.ToString() == allInfo);
}

SCENARIO("test 8: cylinder ToString test")
{
	std::string allInfo = "Cylinder\n  Density: 2.000000\n  Volume: 392.500000\n  Mass: 785.000000\n  Base radius: 5\n  Height: 5\n";
	CCylinder cylinder(2, 5, 5);
	REQUIRE(cylinder.ToString() == allInfo);
}

SCENARIO("test 9: parallelepiped ToString test")
{
	std::string allInfo = "Parallelepiped\n  Density: 2.000000\n  Volume: 125.000000\n  Mass: 250.000000\n  Width: 5\n  Height: 5\n  Depth: 5\n";
	CParallelepiped parallelepiped(2, 5, 5, 5);
	REQUIRE(parallelepiped.ToString() == allInfo);
}

SCENARIO("test 10: compound ToString test")
{
	std::string allInfo = "Compound\n  Density: 1.500000\n  Volume: 1046.666667\n  Mass: 1570.000000\n{\n  Sphere\n    Density: 2.000000\n    Volume: 523.333333\n    Mass: 1046.666667\n    Radius: 5\n  Sphere\n    Density: 1.000000\n    Volume: 523.333333\n    Mass: 523.333333\n    Radius: 5\n}\n";
	CCompound compound;
	//compound.AddChildBody(std::make_shared<CSphere>(CSphere(2, 5)));
	//compound.AddChildBody(std::make_shared<CSphere>(CSphere(1, 5)));
	//REQUIRE(compound.ToString() == allInfo);
}

SCENARIO("test 11: looping compound test")
{
	std::shared_ptr<CCompound> comp1 = std::make_shared<CCompound>();
	std::shared_ptr<CCompound> comp2 = std::make_shared<CCompound>();
	std::shared_ptr<CCompound> comp3 = std::make_shared<CCompound>();
	comp2->AddChildBody(comp3);
	comp1->AddChildBody(comp2);
	REQUIRE(comp3->AddChildBody(comp1) == false);
}