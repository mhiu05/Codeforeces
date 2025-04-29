#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define sec second
#define endl "\n"
#define faster ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
using namespace std;

const int mod = 1e9 + 7;
const int MAXN = 100005;

void solve()
{
    for (int i = 0; i < 3; ++i)
    {
        string s;
        cin >> s;
        map<char, int> mp;
        mp['A'] = 0;
        mp['B'] = 0;
        mp['C'] = 0;

        for (char c : s)
        {
            if (c != '?')
                mp[c] = 1;
        }

        for (auto it : mp)
        {
            if (it.second == 0)
            {
                cout << it.first << endl;
                break;
            }
        }
    }
}

int main()
{
    faster;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}