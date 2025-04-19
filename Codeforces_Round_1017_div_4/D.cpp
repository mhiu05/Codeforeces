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

int check(string p, string s)
{
    int idx_p = 0, idx_s = 0;
    while (idx_p < p.size() - 1 && idx_s < s.size() - 1)
    {
        if (p[idx_p] == s[idx_s])
        {
            if (p[idx_p + 1] != p[idx_p] && p[idx_p] == s[idx_s + 1])
            {
                idx_p += 1;
                idx_s += 2;
            }
            else if (p[idx_p + 1] == p[idx_p] && p[idx_p] == s[idx_s + 1])
            {
                idx_p += 1;
                idx_s += 1;
            }
        }
        else
        {
            return 0;
        }
    }
    if (idx_s == s.size() - 2)
    {
        if (p[p.size() - 1] != s[s.size() - 1] || p[p.size() - 1] != s[s.size() - 2])
            return 0;
    }
    else if (idx_s == s.size() - 1)
    {
        if ()
    }
    return 1;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        string p, s;
        cin >> p >> s;
        if (check(p, s))
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}