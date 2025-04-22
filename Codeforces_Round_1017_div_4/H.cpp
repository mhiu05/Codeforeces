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
        ll n, q;
        cin >> n >> q;
        ll a[n + 1];
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        while (q--)
        {
            ll k, l, r;
            cin >> k >> l >> r;
            ll ans = 0;
            for (int i = l; i <= r; ++i)
            {
                while (k % a[i] == 0)
                {
                    k /= a[i];
                }
                if (k == 1)
                {
                    ans += r - i + 1;
                    break;
                }
                ans += k;
            }
            cout << ans << endl;
        }
    }
    return 0;
}