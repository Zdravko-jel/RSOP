#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


static bool checkLeft(vector<char> a, int b)
{
    int countLeftScobe = 0;
    int countRightScobe = 0;

    for (int i = 0; i < b; i++)
    {
        if (a[i] == '(')
        {
            countLeftScobe++;
        }
        else if (a[i] == ')')
        {
            countRightScobe++;
        }
    }

    if (countLeftScobe == countRightScobe)
    {
        return true;
    }
    else
    {
        return false;
    }
}

static bool checkRight(vector<char> a, int b)
{
    int countLeftScobe = 0;
    int countRightScobe = 0;

    for (int i = b; i < a.size(); i++)
    {
        if (a[i] == '(')
        {
            countLeftScobe++;
        }
        else if (a[i] == ')')
        {
            countRightScobe++;
        }
    }

    if (countLeftScobe == countRightScobe)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string horce;
        cin >> horce;

        vector<char> horceVector;

        for (int i = 0; i < horce.length(); i++)
        {
            horceVector.push_back(horce[i]);

            //cout << horceVector[i] << endl;
        }

        int count = 0;

        for (int i = 0; i < horceVector.size(); i++)
        {
            if (checkLeft(horceVector, i) && checkRight(horceVector, i))
            {
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}
