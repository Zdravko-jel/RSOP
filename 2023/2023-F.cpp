#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int evro, dni;
        cin >> evro >> dni;

        int ednaAk = 1;

        for (int i = 0; i < dni; i++)
        {
            if (evro >= ednaAk)
            {
                evro -= ednaAk;
                ednaAk++;
            }
            else
            {
                evro += ednaAk;
                ednaAk++;
            }
        }

        cout << evro << endl;
    }

    return 0;
}