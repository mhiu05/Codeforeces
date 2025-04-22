#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 7;
const ll mod = 1e9 + 7;
random_device rd;
mt19937 rng(rd());

ll pr[N];
vector<ll> g[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 2; i < N; i++)
    {
        for (ll j = i; j < N; j += i)
            g[j].push_back(i);
    }
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        ll a[n + 1];
        map<ll, vector<ll>> d;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            d[a[i]].push_back(i);
        }
        while (q--)
        {
            ll k, l, r;
            cin >> k >> l >> r;
            ll ans = 0;
            vector<pair<ll, ll>> v;
            for (ll i : g[k])
            {
                ll x = lower_bound(d[i].begin(), d[i].end(), l) - d[i].begin();
                if (x < d[i].size() && d[i][x] <= r)
                    v.push_back({d[i][x], i});
            }
            sort(v.begin(), v.end());
            for (auto it : v)
            {
                ans += (it.first - l) * k;
                while (k % it.second == 0)
                    k /= it.second;
                l = it.first;
            }
            ans += k * (r - l + 1);
            cout << ans << "\n";
        }
    }
}