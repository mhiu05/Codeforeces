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

int main()
{
    faster;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string tmp;
        cin >> tmp;
        string s = tmp;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'a' || s[i] == 'e')
            {
                s[i] = 'V';
            }
            else
                s[i] = 'C';
        }
        vector<int> idx;
        for (int i = 1; i < s.size() - 2; ++i)
        {
            if (s[i + 2] == 'V')
            {
                idx.push_back(i);
            }
            else
            {
                idx.push_back(i + 1);
            }
        }
    }
    return 0;
}