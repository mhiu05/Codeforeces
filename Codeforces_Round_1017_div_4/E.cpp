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
        ll n;
        cin >> n;
        ll a[n];
        for (ll &x : a)
            cin >> x;
        ll cnt[30] = {0};
        // đếm bit 1
        for (int x : a)
        {
            for (int i = 0; i < 30; ++i)
            {
                if (x & (1 << i))
                {
                    cnt[i]++;
                }
            }
        }

        // solve
        ll max_sum = 0;
        for (int x : a)
        {
            ll curr_sum = 0;
            for (int i = 0; i < 30; ++i)
            {
                if (x & (1 << i))
                {
                    curr_sum = curr_sum + 1ll * (n - cnt[i]) * (1 << i);
                }
                else
                    curr_sum = curr_sum + 1ll * cnt[i] * (1 << i);
            }
            max_sum = max(max_sum, curr_sum);
        }
        cout << max_sum << endl;
    }
    return 0;
}