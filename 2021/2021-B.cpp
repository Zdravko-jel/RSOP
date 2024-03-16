#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> resultSets;

void BackTrack(vector<int> tempSet, vector<int> array, int start)
{
	resultSets.push_back(tempSet);

	for (int i = start; i < array.size(); i++)
	{
		tempSet.push_back(array[i]);

		BackTrack(tempSet, array, i + 1);

		tempSet.pop_back();
	}
}

void Subsets(vector<int> array)
{
	vector<int> temp;

	BackTrack(temp, array, 0);
}

int main()
{
    int n;
	while (cin >> n)
	{
		resultSets.clear();

		vector<int> nNumbers;

		for (int i = 0; i < n; i++)
		{
			int ni;
			cin >> ni;

			nNumbers.push_back(ni);
		}

		Subsets(nNumbers);

		int m;
		cin >> m;
		
		vector<string> answer;

		for (int i = 0; i < m; i++)
		{
			int mi;
			cin >> mi;
			
			bool foundSum = false;

			for (int j = 0; j < resultSets.size(); j++)
			{
				int sum = 0;

				for (int z = 0; z < resultSets[j].size(); z++)
				{
					sum += resultSets[j][z];
				}

				if (sum == mi)
				{
					foundSum = true;
					answer.push_back("yes");
					break;
				}
			}

			if (!foundSum)
			{
				answer.push_back("no");
			}
		}

		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << " ";
		}

		cout << endl;
	}
    return 0;
}