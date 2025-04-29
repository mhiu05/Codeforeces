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
const int MAXN = 1e5;

vector<vector<int>> divisor(MAXN + 1);

void sieve()
{
    for (int i = 2; i <= MAXN; ++i)
    {
        for (int j = 1; j <= sqrt(i); ++j)
        {
            if (i % j == 0)
            {
                divisor[i].push_back(j);
                if (j * j != i)
                {
                    divisor[i].push_back(i / j);
                }
            }
        }
    }
}

int main()
{
    faster();
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> v(n + 1);
        map<ll, vector<ll>> mp;

        for (int i = 1; i <= n; ++i)
        {
            cin >> v[i];
            mp[v[i]].push_back(i);
        }

        while (q--)
        {
            ll k, l, r;
            cin >> k >> l >> r;
            vector<int> index;
            for (int x : divisor[k])
            {
                if (x == 1)
                    continue;
                if (!mp[x].empty())
                {
                    auto it = lower_bound(mp[x].begin(), mp[x].end(), l);
                    if (it != mp[x].end())
                    {
                        if (*it <= r)
                        {
                            index.push_back(*it);
                        }
                    }
                }
            }
            sort(index.begin(), index.end());
            ll ans = 0;
            int currPos = l;
            for (int i = 0; i < index.size(); ++i)
            {
                ans += k * (index[i] - currPos);
                while (k % v[index[i]] == 0)
                {
                    k /= v[index[i]];
                }
                currPos = index[i];
            }
            ans += k * (r - currPos + 1);
            cout << ans << endl;
        }
    }
    return 0;
}