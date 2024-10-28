#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "../CMyStack/CMyStack.hpp"
#include <iostream>

//CHECK_THROWS_AS(strStack.getTop(), std::out_of_range);

SCENARIO("test 1: create string stack")
{
	CMyStack<std::string> strStack;
	strStack.push("aaa");
	strStack.push("bbb");
	strStack.push("ccc");
	REQUIRE(strStack.getTop() == "ccc");
	strStack.pop();
	REQUIRE(strStack.getTop() == "bbb");
	strStack.pop();
	REQUIRE(strStack.getTop() == "aaa");
	strStack.pop();
	REQUIRE(strStack.isEmpty() == true);
}

SCENARIO("test 2: create int stack")
{
	CMyStack<int> intStack;
	intStack.push(111);
	intStack.push(222);
	intStack.push(333);
	REQUIRE(intStack.getTop() == 333);
	intStack.pop();
	REQUIRE(intStack.getTop() == 222);
	intStack.pop();
	REQUIRE(intStack.getTop() == 111);
	intStack.pop();
	REQUIRE(intStack.isEmpty() == true);
}

SCENARIO("test 3: clear stack")
{
	CMyStack<int> intStack;
	intStack.push(111);
	intStack.push(222);
	intStack.push(333);
	intStack.Clear();
	REQUIRE(intStack.isEmpty() == true);
}

SCENARIO("test 4: stack throw")
{
	CMyStack<int> intStack;
	CHECK_THROWS_AS(intStack.getTop(), std::out_of_range);
}

SCENARIO("test 5: construktor with other stack")
{
	CMyStack<int> intStack;
	intStack.push(111);
	intStack.push(222);
	intStack.push(333);
	//CMyStack<int> newIntStack(intStack);
	//REQUIRE(newIntStack.getTop() == 333);
	//newIntStack.pop();
	//REQUIRE(newIntStack.getTop() == 222);
	//newIntStack.pop();
	//REQUIRE(newIntStack.getTop() == 111);
	//newIntStack.pop();
	//REQUIRE(newIntStack.isEmpty() == true);
}