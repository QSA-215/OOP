#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "../Calculator/Calculator.h"
#include <iostream>
// вынести дублирование кода в функцию

void CreateVars(Calculator calc)
{
	calc.AddVar("age");
	calc.LetVar("age", 16);
	calc.AddVar("age1");
	calc.LetVar("age1", 8);
}

SCENARIO("test 1: add var")
{
	Calculator calc;
	calc.AddVar("age");
	REQUIRE(calc.GetVars().size() == 1);
}

SCENARIO("test 2: check identifier")
{
	Calculator calc;
	calc.AddVar("age");
	REQUIRE(calc.IdentifierExists("age"));
}

SCENARIO("test 3: check var")
{
	Calculator calc;
	calc.AddVar("age");
	calc.LetVar("age", 14);
	REQUIRE(calc.FindValue("age") == 14);
}

SCENARIO("test 4: add fn")
{
	Calculator calc;
	CreateVars(calc);
	calc.AddFn("ageSum", "age", "+", "age1");
	REQUIRE(calc.GetFns().size() == 1);
	REQUIRE(calc.IdentifierExists("ageSum"));
}

SCENARIO("test 5: add short fn")
{
	Calculator calc;
	calc.AddVar("age");
	calc.LetVar("age", 14);
	calc.AddFn("AgeFunc", "age");
	REQUIRE(calc.GetFns().size() == 1);
	REQUIRE(calc.IdentifierExists("AgeFunc"));
	REQUIRE(calc.FindValue("AgeFunc") == calc.FindValue("age"));
}

SCENARIO("test 6: check Addition")
{
	Calculator calc;
	calc.AddVar("age");
	calc.LetVar("age", 16);
	calc.AddVar("age1");
	calc.LetVar("age1", 8);
	calc.AddFn("sum", "age", "+", "age1");
	REQUIRE(calc.FindValue("sum") == 24);
}

SCENARIO("test 7: check Subtraction")
{
	Calculator calc;
	calc.AddVar("age");
	calc.LetVar("age", 16);
	calc.AddVar("age1");
	calc.LetVar("age1", 8);
	calc.AddFn("substr", "age", "-", "age1");
	REQUIRE(calc.FindValue("substr") == 8);
}

SCENARIO("test 8: check Multiplication")
{
	Calculator calc;
	calc.AddVar("age");
	calc.LetVar("age", 16);
	calc.AddVar("age1");
	calc.LetVar("age1", 8);
	calc.AddFn("mult", "age", "*", "age1");
	REQUIRE(calc.FindValue("mult") == 128);
}

SCENARIO("test 9: check Division")
{
	Calculator calc;
	calc.AddVar("age");
	calc.LetVar("age", 16);
	calc.AddVar("age1");
	calc.LetVar("age1", 8);
	calc.AddFn("div", "age", "/", "age1");
	REQUIRE(calc.FindValue("div") == 2);
}