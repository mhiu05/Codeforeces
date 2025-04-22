#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

using ll = long long;

const int mod = 1e9 + 7;
const int MAXN = 100005;

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v;
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        for (int i = v.size() - 1; i >= 0; --i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (v[i][j] == '#')
                {
                    cout << j + 1 << " ";
                    continue;
                }
            }
        }
        cout << endl;
    }
    return 0;
}