#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

map<string, char> coding;
string result;
string encrypt;

void findResult(string temp, int start)
{
	if (start == encrypt.length())
	{
		return;
	}

	temp += encrypt[start];

	for (auto code : coding)
	{
		if (code.first == temp)
		{
			result += code.second;
			temp = "";
		}
	}

	findResult(temp, start + 1);
}

int main()
{
    int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}

		coding.clear();
		result = "";

		bool right = true;

		for (int i = 0; i < n; i++)
		{
			string input;
			cin >> input;

			string toInt = input.substr(0, 8);
			string code = input.substr(8, input.length() - 8);

			int asciiNumber = stoi(toInt, 0, 2);
			char codeChar = (char)asciiNumber;

			if (!coding.empty())
			{
				for (auto cods : coding)
				{
					string check1 = cods.first.substr(0, code.length());
					string check2 = code.substr(0, cods.first.length());
					
					if (check1 == code || check2 == cods.first)
					{
						right = false;
						break;
					}
				}

				if (right)
				{
					coding[code] = codeChar;
				}
			}
			else
			{
				coding[code] = codeChar;
			}
		}

		cin >> encrypt;
		
		if (!right)
		{
			result = "Wrong code table!";
		}
		else
		{
			findResult("", 0);
		}

		cout << result << endl;
	}

	return 0;
}