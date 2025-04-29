#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n), ps(1);
        for (ll &r : a)
        {
            cin >> r;
            ps.push_back(ps.back() + r);
        }
        for (ll &r : a)
        {
            ps.push_back(ps.back() + r);
        }
        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            ll i = l / n, j = r / n;
            l %= n;
            r %= n;
            cout << ps[n] * (j - i + 1) - (ps[i + l] - ps[i]) - (ps[j + n] - ps[j + r + 1]) << "\n";
        }
    }
}