#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool haveCommonDigit(double num1, double num2) {
	// Convert the integers to strings
	string strNum1 = to_string(num1);
	string strNum2 = to_string(num2);

	// Use an unordered set to keep track of unique digits in the first number
	unordered_set<char> digitSet;

	// Populate the set with digits from the first number
	for (char digit : strNum1) 
	{
		if (digit == '.')
		{
			break;
		}

		digitSet.insert(digit);
	}

	// Check if any digit in the second number is in the set
	for (char digit : strNum2) 
	{
		if (digit == '.')
		{
			break;
		}

		if (digitSet.count(digit) > 0) {
			return true; // At least one common digit found
		}
	}

	return false; // No common digit found
}

double FindFriends(vector<double> numbers) 
{
	int pairs = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = 0; j < numbers.size() - 1; j++)
		{
			if (haveCommonDigit((int)numbers[j], (int)numbers[j+1]))
			{
				pairs++;
			}
			else
			{
				double temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}

	return pairs / 2;
}

int main()
{
    int n;
	while (cin >> n)
	{
		vector<double> numbers;

		for (int i = 0; i < n; i++)
		{
			double number;
			cin >> number;

			numbers.push_back(number);
		}

		int friendPairs = FindFriends(numbers);

		cout << friendPairs << endl;
	}
    return 0;
}