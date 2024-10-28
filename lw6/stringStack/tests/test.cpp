#include "pch.h"
#include <gtest/gtest.h>
#include "../stringStack/stringStack.h"
// тесты можно на catch!!!!!
TEST(StringStackTest, stackConstruktor1)
{
	CStringStack strStack;
	EXPECT_THROW(strStack.getTop(), std::out_of_range);
}

TEST(StringStackTest, stackConstruktor2)
{
	CStringStack strStack;
	strStack.push("aaa");
	CStringStack newStrStack(strStack);
	EXPECT_EQ(newStrStack.getTop(), "aaa");
}

TEST(StringStackTest, stackConstruktor3)
{
	CStringStack strStack;
	strStack.push("aaa");
	CStringStack newStrStack(std::move(strStack));
	EXPECT_EQ(newStrStack.getTop(), "aaa");
	EXPECT_THROW(strStack.getTop(), std::out_of_range);
}

TEST(StringStackTest, stackPush)
{
	CStringStack strStack;
	strStack.push("aaa");
	EXPECT_EQ(strStack.getTop(), "aaa");
}

TEST(StringStackTest, stackPop)
{
	CStringStack strStack;
	strStack.push("aaa");
	strStack.push("bbb");
	strStack.pop();
	EXPECT_EQ(strStack.getTop(), "aaa");
}

TEST(CStringStackTest, popEmptyStack)
{
	CStringStack stack;
	EXPECT_THROW(stack.pop(), std::out_of_range);
}