#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> results;

string sumStrings(const std::string& str1, const std::string& str2) {
    int maxLen = std::max(str1.length(), str2.length());
    string result;
    int carry = 0;

    for (int i = 1; i <= maxLen; ++i) {
        int digit1 = (i <= str1.length()) ? (str1[str1.length() - i] - '0') : 0;
        int digit2 = (i <= str2.length()) ? (str2[str2.length() - i] - '0') : 0;

        int total = digit1 + digit2 + carry;
        result.insert(result.begin(), '0' + (total % 10));
        carry = total / 10;
    }

    if (carry) {
        result.insert(result.begin(), '0' + carry);
    }

    return result;
}

void randomize(string input, int start)
{
    if(find(results.begin(), results.end(), input) == results.end())
        results.push_back(input);

    for (int i = start; i < input.length(); i++)
    {
        char temp = input[i];
        input[i] = '0';
        randomize(input, i + 1);
        input[i] = temp;
    }
}

int main()
{
    string n;
    while (cin >> n)
    {
        results.clear();
        if (n == "0")
            break;
        randomize(n, 0);
        string sum = results[0];
        for (int i = 1; i < results.size(); i++)
        {
            sum = sumStrings(sum, results[i]);
        }
        cout << sum << endl;
    }
}