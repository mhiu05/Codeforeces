#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
// #define int long long
#define pii pair<int, int>
#define se second
#define fi first
#define pb push_back
#define maxel(v) *max_element(v.begin(), v.end())
#define minel(v) *min_element(v.begin(), v.end())
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vec<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int mask = (1 << k) - 1;
    vec<vec<int>> add(n + 2), rem(n + 2);
    vec<pii> dp_prev, dp_curr;

    for (int r = 1; r <= n; r++)
    {
        dp_curr.clear();
        dp_curr.pb({a[r], r});
        for (auto &p : dp_prev)
        {
            int cur = (~(p.fi | a[r])) & mask;
            int l = p.se;
            bool found = false;
            for (auto &q : dp_curr)
            {
                if (q.fi == cur)
                {
                    q.se = min(q.se, l);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                dp_curr.pb({cur, l});
            }
        }
        for (auto &p : dp_curr)
        {
            int cur = p.fi;
            int l = p.se;
            if (l < r)
            {
                add[l].pb(cur);
                rem[r + 1].pb(cur);
            }
        }
        dp_prev.swap(dp_curr);
    }
    vec<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
        ans[i] = a[i];
    map<int, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        for (int v : add[i])
            cnt[v]++;
        for (int v : rem[i])
        {
            auto it = cnt.find(v);
            if (it->se == 1)
                cnt.erase(it);
            else
                it->se--;
        }
        if (!cnt.empty())
        {
            int mx = cnt.rbegin()->fi;
            ans[i] = max(ans[i], mx);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << (i == n ? "\n" : " ");
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; ++i)
        solve();
}
