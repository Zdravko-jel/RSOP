#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> resultSets;

void BackTrack(string tempSet, string array, int start)
{
    string original = tempSet;
    reverse(tempSet.begin(), tempSet.end());

    if (find(resultSets.begin(), resultSets.end(), original) == resultSets.end() && tempSet.length() > 1 
        && find(resultSets.begin(), resultSets.end(), tempSet) == resultSets.end())
    {
        resultSets.push_back(tempSet);
    }

    for (int i = start; i < array.length(); i++)
    {
        tempSet += array[i];

        BackTrack(tempSet, array, i + 1);

        tempSet.erase(tempSet.length() - 1);
    }
}

void Subsets(string array) 
{
    string temp = "";

    BackTrack(temp, array, 0);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        resultSets.clear();
        string strink;
        cin >> strink;

        Subsets(strink);

        int counter = 0;

        for (int i = 0; i < resultSets.size(); i++)
        {
            int countZero = 0;
            int countOne = 0;

            for (int j = 0; j < resultSets[i].length(); j++)
            {
                if (resultSets[i][j] == '0')
                {
                    countZero++;
                }
                else
                {
                    countOne++;
                }
            }

            if (countOne >= countZero)
            {
                counter++;
            }
        }

        cout << counter << endl;
    }

    return 0;
}