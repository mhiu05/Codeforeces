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

void solve(ll n, ll m, ll k)
{
    if (m % k == 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            int start;
            if (i % 2 == 0)
                start = 2;
            else
                start = 1;
            for (int j = start; j <= m + start - 1; ++j)
            {
                if (j % k != 0)
                    cout << j % k << " ";
                else
                    cout << k << " ";
            }
            cout << endl;
        }
    }
    else
    {
        int start = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cout << start << " ";
                ++start;
                if (start == k + 1)
                    start = 1;
            }
            cout << endl;
        }
    }
}

int main()
{
    faster();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        solve(n, m, k);
    }
    return 0;
}