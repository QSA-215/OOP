#include "CMyStack.hpp"
#include <iostream>
#include <string>

int main()
{
	CMyStack<int> intStack;
	CMyStack<std::string> strStack;
	intStack.push(15);
	intStack.push(16);
	intStack.push(17);
	std::cout << intStack.getTop() << std::endl;
	intStack.pop();
	std::cout << intStack.getTop() << std::endl;
	intStack.pop();
	std::cout << intStack.getTop() << std::endl;

	strStack.push("aaa");
	strStack.push("bbb");
	strStack.push("ccc");
	std::cout << strStack.getTop() << std::endl;
	strStack.pop();
	std::cout << strStack.getTop() << std::endl;
	strStack.pop();
	std::cout << strStack.getTop() << std::endl;
}