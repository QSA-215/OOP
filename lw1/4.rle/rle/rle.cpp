#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void OpenFilesWithAction(string modeStr, string inputFileName, string outputFileName)
{
	string mode = modeStr;
	if ((mode != "pack") && (mode != "unpack"))
	{
		cout << "Wrong program mode." << endl;
		exit(1);
	}

	ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		cout << "Can`t open input file" << endl;
		exit(1);
	}

	ofstream outputFile(outputFileName);
	if (!outputFile.is_open())
	{
		cout << "Can`t open output file" << endl;
		exit(1);
	}

	if (mode == "pack")
	{
		char ch1, ch2;
		int numberOfCh = 1;
		ch2 = inputFile.get();
		string outputStr;
		while (ch2 != EOF)
		{
			while ((ch2 != '\n') && (ch2 != EOF))
			{
				ch1 = ch2;
				ch2 = inputFile.get();
				if ((ch1 == ch2) && (numberOfCh < 255))
					numberOfCh += 1;
				else
				{
					string tempStr = to_string(numberOfCh) + ", \'" + ch1 + "\', ";
					outputStr += tempStr;
					numberOfCh = 1;
				}
			}
			outputFile << outputStr.substr(0, outputStr.size() - 2) << endl;
			outputStr = "";
			ch1 = ch2;
			ch2 = inputFile.get();
		}
	}
	else
	{
		int numberOfCh;
		string str;
		char ch = inputFile.get();
		while (ch != EOF)
		{
			while ((ch != '\n') && (ch != EOF))
			{
				if (('0' < ch) && (ch < '9'))
					str += ch;
				else
				{
					numberOfCh = stoi(str);
					str = "";
					for (int i = 0; i < 6; ++i)
						if ((ch != '\n') && (ch != EOF))
						{
							ch = inputFile.get();
							str += ch;
						}
					outputFile << string(numberOfCh, str[2]);
					if (str[4] == '\n')
						outputFile << endl;
					str = "";
				}
				if (ch != EOF)
					ch = inputFile.get();
			}
			if (ch != EOF)
			{
				outputFile << endl;
				ch = inputFile.get();
			}
		}
	}

	outputFile.close();
	inputFile.close();
}

int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		cout << "Wrong program input." << endl;
		return 1;
	}
	
	OpenFilesWithAction(argv[1], argv[2], argv[3]);

	return 0;
}