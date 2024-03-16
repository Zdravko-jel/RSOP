#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        
        int maxX = -1000, maxY = -1000, minX = 1000, minY = 1000;

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;

            if (x > maxX)
            {
                maxX = x;
            }

            if (x < minX)
            {
                minX = x;
            }

            if (y > maxY)
            {
                maxY = y;
            }

            if (y < minY)
            {
                minY = y;
            }
        }

        int x = abs(maxX - minX);
        int y = abs(maxY - minY);

        if (x > y)
        {
            y = x;
        }
        else
        {
            x = y;
        }

        cout << 4 * (x + 2) << endl;
    }

    return 0;
}