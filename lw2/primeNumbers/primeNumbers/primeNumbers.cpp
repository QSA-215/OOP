#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	set<int> primeNumbersSet;
	vector<bool> numbers((upperBound / 2) + 1, true);
	int i = 3;

	while (i * i <= upperBound)
	{
		if (numbers[i / 2] != false)
		{
			int j = i * i;
			while (j <= upperBound)
			{
				numbers[j / 2] = false;
				j += 2 * i;
			}
		}
		i += 2;
	}
	if (upperBound >= 2)
		primeNumbersSet.insert(2);

	for (int o = 1; o < upperBound / 2; ++o)
		if (numbers[o] != false)
			primeNumbersSet.insert((o * 2) + 1);
	return primeNumbersSet;
}

int main()
{
	int upperBound = 100000000;

	set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);

	for (int i : primeNumbers)
		cout << i << endl;
}

/*
	vector<bool> numbers(upperBound + 1, true);
	numbers[0] = false;
	numbers[1] = false;
	int i = 2;

	while (i * i < upperBound)
	{
		if (numbers[i] != false)
		{
			int j = i * i;
			while (j <= upperBound)
			{
				numbers[j] = false;
				j += i;
			}
		}
		i += 1;
	}

	for (int o = 2; o < upperBound; ++o)
		if (numbers[o] != false)
			primeNumbersSet.insert(o);
	return primeNumbersSet;
*/