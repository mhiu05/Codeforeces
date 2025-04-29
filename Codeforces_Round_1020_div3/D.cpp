#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(vector<ll> a, vector<ll> b, int n, int m)
{
    ll prefix[m], suffix[m];
    for (int i = 0; i < m; ++i)
    {
        prefix[i] = LLONG_MAX;
        suffix[i] = LLONG_MIN;
    }
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (j >= m)
            break;
        if (a[i] >= b[j])
        {
            prefix[j] = i;
            ++j;
        }
    }
    int jr = m - 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (jr < 0)
            break;
        if (a[i] >= b[jr])
        {
            suffix[jr] = i;
            --jr;
        }
    }
    if (prefix[m - 1] != LLONG_MAX)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = LLONG_MAX;
    for (int i = 1; i < m - 1; ++i)
    {
        if (prefix[i - 1] < suffix[i + 1])
        {
            ans = min(ans, b[i]);
        }
    }
    if (prefix[m - 2] != LLONG_MAX)
    {
        ans = min(ans, b[m - 1]);
    }
    if (suffix[1] != LLONG_MIN)
    {
        ans = min(ans, b[0]);
    }
    if (ans == LLONG_MAX)
    {
        ans = -1;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        for (ll &x : a)
            cin >> x;
        for (ll &x : b)
            cin >> x;
        solve(a, b, n, m);
    }

    return 0;
}
