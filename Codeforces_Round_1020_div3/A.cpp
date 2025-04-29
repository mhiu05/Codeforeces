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
        string s;
        cin >> s;
        vector<string> v;
        for (int i = 0; i < n; ++i)
        {
            string tmp = s;
            if (tmp[i] == '1')
                tmp[i] = '0';
            else
                tmp[i] = '1';
            v.push_back(tmp);
        }
        int ans = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < v[i].size(); ++j)
            {
                if (v[i][j] == '1')
                    ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}