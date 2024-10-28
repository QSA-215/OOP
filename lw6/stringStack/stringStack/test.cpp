#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "../stringStack/stringStack.h"
#include <iostream>

SCENARIO("test 1: create empty stack")
{
	CStringStack strStack;
	CHECK_THROWS_AS(strStack.getTop(), std::out_of_range);
}

SCENARIO("test 2: create stack by const stack")
{
	CStringStack strStack;
	strStack.push("aaa");
	CStringStack newStrStack(strStack);
	REQUIRE(newStrStack.getTop() == "aaa");
}

SCENARIO("test 3: create stack by &&stack")
{
	CStringStack strStack;
	strStack.push("aaa");
	CStringStack newStrStack(std::move(strStack));
	REQUIRE(newStrStack.getTop() == "aaa");
	CHECK_THROWS_AS(strStack.getTop(), std::out_of_range);
}

SCENARIO("test 4: push stack")
{
	CStringStack strStack;
	strStack.push("aaa");
	REQUIRE(strStack.getTop() == "aaa");
}

SCENARIO("test 5: pop stack")
{
	CStringStack strStack;
	strStack.push("aaa");
	strStack.push("bbb");
	strStack.pop();
	REQUIRE(strStack.getTop() == "aaa");
}

SCENARIO("test 6: pop empty stack")
{
	CStringStack strStack;
	CHECK_THROWS_AS(strStack.pop(), std::out_of_range);
}

SCENARIO("test 7: check create big stack by another")
{
	CStringStack strStack;
	strStack.push("aaa");
	strStack.push("bbb");
	strStack.push("ccc");
	CStringStack newStack(strStack);
	REQUIRE(newStack.getTop() == "ccc");
	newStack.pop();
	REQUIRE(newStack.getTop() == "bbb");
	newStack.pop();
	REQUIRE(newStack.getTop() == "aaa");
	newStack.pop();
}

SCENARIO("test 8: check operator=")
{
	CStringStack strStack;
	strStack.push("aaa");
	strStack.push("bbb");
	strStack.push("ccc");
	CStringStack newStack;
	newStack = strStack;
	REQUIRE(newStack.getTop() == "ccc");
	newStack.pop();
	REQUIRE(newStack.getTop() == "bbb");
	newStack.pop();
	REQUIRE(newStack.getTop() == "aaa");
	newStack.pop();
}

SCENARIO("test 9: check &&operator=")
{
	CStringStack strStack;
	strStack.push("aaa");
	strStack.push("bbb");
	strStack.push("ccc");
	CStringStack newStack;
	newStack = std::move(strStack);
	REQUIRE(newStack.getTop() == "ccc");
	newStack.pop();
	REQUIRE(newStack.getTop() == "bbb");
	newStack.pop();
	REQUIRE(newStack.getTop() == "aaa");
	newStack.pop();
}