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

ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        int mark[n + 1] = {0};
        for (ll &x : a)
        {
            cin >> x;
            mark[x]++;
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (mark[i] != 0)
            {
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}