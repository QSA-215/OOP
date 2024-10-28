#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string ReplaceString(string subject, string searchString, string replaceString)
{
	string result;
	while (subject.find(searchString) != string::npos)    // инициализация в while
	{
		int position = subject.find(searchString);
		result += subject.substr(0, position) + replaceString;
		subject = subject.substr(position + searchString.size(), subject.size() - position + searchString.size() - 1);
	}
	result += subject;
	return result;
}

void CopyStreamWithReplacement(istream& input, ostream& output, string searchString, string replaceString)
{
	string line;
	while (getline(input, line))
		if (searchString != "")
			output << ReplaceString(line, searchString, replaceString) << endl;
		else
			output << line << endl;
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "There are no name of input or output file." << endl;
		return 1;
	}
	{

	string searchString;
	string replaceString;
	if (argc > 3)
		searchString = argv[3];
	if (argc > 4)
		replaceString = argv[4];

	ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
		cout << "Can`t open input file" << endl;
		return 1;
	}

	ofstream outputFile(argv[2]);
	if (!outputFile.is_open())
	{
		cout << "Can`t open output file" << endl;
		return 1;
	}

	CopyStreamWithReplacement(inputFile, outputFile, searchString, replaceString);

	outputFile.close();
	inputFile.close();
	return 0;
}