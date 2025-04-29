#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        map<int, int> mp;
        for (char c : s)
        {
            mp[c - '0']++;
        }

        for (int i = 1; i <= 10; ++i)
        {
            for (int j = 10 - i; j <= 9; ++j)
            {
                if (mp[j] != 0)
                {
                    cout << j;
                    mp[j]--;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}