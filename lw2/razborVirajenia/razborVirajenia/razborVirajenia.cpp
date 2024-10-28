#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string statement;
	getline(cin, statement);

	while (statement[0] == '(')
	{
		vector<string> bufer;
		string tempStatement;
		string tempNum;
		for (char stCh : statement)
		{
			if (stCh == '(') // выгрузка буфера, его очистка и добавление туда скобки
			{
				if (bufer.size() > 0)
				{
					tempStatement += bufer[0] + bufer[1];
					if (bufer.size() == 3)
						tempStatement += ' ' + bufer[2];
				}
				bufer.clear();
				bufer.push_back("(");
			}

			if ((stCh == '+') || (stCh == '*')) // добавление знака операции в буфер
				bufer.push_back(string(1, stCh));

			if (((stCh <= '9') && (stCh >= '0')) || (stCh == '-')) // создание числа
				tempNum += stCh;

			if (((stCh == ' ') || (stCh == ')')) && (tempNum != "")) // добавление числа в буфер
			{
				if (bufer.size() < 3)
					bufer.push_back(tempNum);
				else
					if (bufer[1] == "+")
						bufer[2] = to_string(stoi(bufer[2]) + stoi(tempNum));
					else
						bufer[2] = to_string(stoi(bufer[2]) * stoi(tempNum));
				tempNum = "";
			}

			if (stCh == ')') // выгрузка буфера и его очистка
			{
				if (bufer.size() > 0)
					if (bufer[0] == "(")
						tempStatement += ' ' + bufer[bufer.size() - 1];
					else
					{
						for (string item : bufer)
							tempStatement += ' ' + item;
						tempStatement += ')';
					}
				else
					tempStatement += ")";
				bufer.clear();
			}
		}
		statement = tempStatement;
	}
	std::cout << statement.substr(1, statement.size() - 1) << endl;
}