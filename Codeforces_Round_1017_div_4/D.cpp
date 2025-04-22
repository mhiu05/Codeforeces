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

int check(string s, string p)
{
    int i = 0, j = 0;
    while (i < s.size() && j < p.size())
    {
        if (s[i] != p[j])
            return 0;
        int curr = s[i];
        int cnt_s = 0;
        while (i < s.size() && s[i] == curr)
        {
            ++i;
            ++cnt_s;
        }
        int cnt_p = 0;
        while (j < p.size() && p[j] == curr)
        {
            ++j;
            ++cnt_p;
        }
        if (cnt_p < cnt_s || cnt_p > 2 * cnt_s)
            return 0;
    }
    if (i == s.size() && j == p.size())
        return 1;
    else
        return 0;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        string s, p;
        cin >> s >> p;
        if (check(s, p))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}