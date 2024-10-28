#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "../CMyString/CMyString.h"
#include <iostream>
#include <sstream>

SCENARIO("test 1: create empty string")
{
	CMyString str;
	REQUIRE(str.GetLength() == 0);
	REQUIRE(str.GetCapacity() == 0);
	REQUIRE(strcmp(str.GetStringData(), "\0") == 0);
}

SCENARIO("test 2: create not empty string")
{
	CMyString str("aaa");
	REQUIRE(str.GetLength() == 3);
	REQUIRE(str.GetCapacity() == 3);
	REQUIRE(strcmp(str.GetStringData(), "aaa") == 0);
}

SCENARIO("test 3: clear string")
{
	CMyString str("aaa");
	REQUIRE(str.GetLength() == 3);
	REQUIRE(str.GetCapacity() == 3);
	REQUIRE(strcmp(str.GetStringData(), "aaa") == 0);
	str.Clear();
	REQUIRE(str.GetLength() == 0);
	REQUIRE(str.GetCapacity() == 0);
	REQUIRE(strcmp(str.GetStringData(), "") == 0);
}

SCENARIO("test 4: create 3-size 'aaaaa' string")
{
	CMyString str("aaaaa", 3);
	REQUIRE(str.GetLength() == 3);
	REQUIRE(str.GetCapacity() == 3);
	REQUIRE(strcmp(str.GetStringData(), "aaa") == 0);
}

SCENARIO("test 5: copy string")
{
	CMyString str("aaa");
	REQUIRE(str.GetLength() == 3);
	REQUIRE(str.GetCapacity() == 3);
	REQUIRE(strcmp(str.GetStringData(), "aaa") == 0);
	CMyString str1(str);
	REQUIRE(str1.GetLength() == 3);
	REQUIRE(str1.GetCapacity() == 3);
	REQUIRE(strcmp(str1.GetStringData(), "aaa") == 0);
}

SCENARIO("test 6: move string")
{
	CMyString str("aaa");
	REQUIRE(str.GetLength() == 3);
	REQUIRE(str.GetCapacity() == 3);
	REQUIRE(strcmp(str.GetStringData(), "aaa") == 0);
	CMyString str1(std::move(str));
	REQUIRE(str1.GetLength() == 3);
	REQUIRE(str1.GetCapacity() == 3);
	REQUIRE(strcmp(str1.GetStringData(), "aaa") == 0);

	REQUIRE(str.GetLength() == 0);
	REQUIRE(str.GetCapacity() == 0);
	REQUIRE(str.GetStringData() == nullptr);
}

SCENARIO("test 7: create CMyString by std::string")
{
	std::string a = "aaa";
	CMyString str(a);
	REQUIRE(str.GetLength() == 3);
	REQUIRE(str.GetCapacity() == 3);
	REQUIRE(strcmp(str.GetStringData(), "aaa") == 0);
}

SCENARIO("test 8: operator=")
{
	CMyString str("aaa");
	CMyString str1 = str;
	REQUIRE(str1.GetLength() == 3);
	REQUIRE(str1.GetCapacity() == 3);
	REQUIRE(strcmp(str1.GetStringData(), "aaa") == 0);
}

SCENARIO("test 9: operator+(empty + str)")
{
	CMyString str("aaa");
	CMyString str1;
	str1 = str1 + str;
	REQUIRE(str1.GetLength() == 3);
	REQUIRE(str1.GetCapacity() == 6);
	REQUIRE(strcmp(str1.GetStringData(), "aaa") == 0);
}

SCENARIO("test 10: operator+(str + str)")
{
	CMyString str("aaa");
	CMyString str1(str);
	str1 = str1 + str;
	REQUIRE(str1.GetLength() == 6);
	REQUIRE(str1.GetCapacity() == 12);
	REQUIRE(strcmp(str1.GetStringData(), "aaaaaa") == 0);
}

SCENARIO("test 11: operator+=")
{
	CMyString str("aaa");
	CMyString str1(str);
	str1 += str;
	REQUIRE(str1.GetLength() == 6);
	REQUIRE(str1.GetCapacity() == 12);
	REQUIRE(strcmp(str1.GetStringData(), "aaaaaa") == 0);
}

SCENARIO("test 12: operator==")
{
	CMyString str("aaa");
	CMyString str1("bbb");
	CMyString str2("aaa");
	REQUIRE((str == str2) == true);
	REQUIRE((str == str1) == false);
}

SCENARIO("test 13: operator!=")
{
	CMyString str("aaa");
	CMyString str1("bbb");
	REQUIRE((str != str1) == true);
}

SCENARIO("test 14: operator<")
{
	CMyString str("aaa");
	CMyString str1("bbb");
	REQUIRE((str < str1) == true);
}

SCENARIO("test 15: operator>")
{
	CMyString str("aaa");
	CMyString str1("bbb");
	REQUIRE((str1 > str) == true);
}

SCENARIO("test 16: operator<=")
{
	CMyString str("aba");
	CMyString str1("bbb");
	REQUIRE((str <= str1) == true);
	REQUIRE((str <= str) == true);
}

SCENARIO("test 17: operator>=")
{
	CMyString str("aaa");
	CMyString str1("bbb");
	REQUIRE((str1 >= str) == true);
	REQUIRE((str >= str) == true);
}

SCENARIO("test 18: operator[](const)")
{
	CMyString str("aaa");
	REQUIRE(str[1] == 'a');
}

SCENARIO("test 19: operator[](not const)")
{
	CMyString str("aaa");
	str[1] = 'b';
	REQUIRE(strcmp(str.GetStringData(), "aba") == 0);
}

SCENARIO("test 20: SubString")
{
	CMyString str("abcde");
	CMyString str1 = str.SubString(1, 3);
	REQUIRE(strcmp(str1.GetStringData(), "bcd") == 0);
}

SCENARIO("test 21: SubString(out of range(length))")
{
	CMyString str("abcde");
	CMyString str1 = str.SubString(1, 9);
	REQUIRE(strcmp(str1.GetStringData(), "bcde") == 0);
}

SCENARIO("test 22: operator<<")
{
	std::ostringstream out;
	CMyString str("aaa");
	out << str;
	REQUIRE(out.str() == "aaa");
}

SCENARIO("test 23: operator>>")
{
	std::stringstream in;
	CMyString str;
	in << "aaa";
	in >> str;
	REQUIRE(strcmp(str.GetStringData(), "aaa") == 0);
}

SCENARIO("test 24: check iterators")
{
	CMyString str("abcde");
	REQUIRE(*str.begin() == 'a');
	REQUIRE(*(str.end() - 1) == 'e');
	REQUIRE(*str.end() == '\0');

	*str.begin() = 'f';
	*(str.end() - 1) = 'p';

	REQUIRE(*str.rbegin() == 'p');
	REQUIRE(*(str.rend() - 1) == 'f');

	str = "abcde";
	REQUIRE(*str.crbegin() == 'e');
	REQUIRE(*(str.crend() - 1) == 'a');
}