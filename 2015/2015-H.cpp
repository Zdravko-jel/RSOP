#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int Sum(vector<int> bob) 
{
    return accumulate(bob.begin(), bob.end(), 0);
}

bool cmp(int one, int two) 
{
    return one > two;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> stokes;
        for (int i = 0; i < n; i++)
        {
            int bob;
            cin >> bob;

            stokes.push_back(bob);
        }

        int x = n / k;

        int sum = Sum(stokes);

        sort(stokes.begin(), stokes.end(), cmp);

        int index = k - 1;

        while (x != 0)
        {
            sum -= stokes[index];
            index += k;
            x--;
        }

        cout << sum << endl;
    }

    return 0;
}