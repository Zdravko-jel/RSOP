#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> variations;
vector<int> prime{1, 2, 3, 5, 7, 11, 13, 17};
 
void DifferentWays(int n)
{
    if (find(prime.begin(), prime.end(), n) != prime.end())
    {
        return;
    }

    vector<int> largest;

    for (int i = n - 1; i > 0; i--)
    {
        if (n % i == 0)
        {
            variations.push_back(i);

            largest.push_back(i);
        }
    }

    for (int i = 0; i < largest.size(); i++)
    {
        DifferentWays(largest[i]);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        variations.clear();
        
        DifferentWays(n + 1);

        map<int, int> dups;

        for (int i = 0; i < variations.size(); i++)
        {
            dups[variations[i]]++;
        }

        int countFirst = 0;
        int countSecond = 0;

        for (auto i = dups.begin(); i != dups.end(); i++)
        {
            countFirst++;

            if (i->second > 1 && i->first != 1)
            {
                countSecond += i->second - 1;
            }
        }

        if (countFirst == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << countFirst + countSecond << endl;
        }
    }
    return 0;
}