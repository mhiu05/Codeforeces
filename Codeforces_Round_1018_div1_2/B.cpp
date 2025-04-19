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

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<ll> l(n), r(n);
        for (ll &x : l)
            cin >> x;
        for (ll &x : r)
            cin >> x;

        vector<ll> min_val(n);
        for (int i = 0; i < n; ++i)
        {
            min_val[i] = min(l[i], r[i]);
        }

        // Sắp xếp giảm dần theo min(l_i, r_i)
        sort(min_val.begin(), min_val.end(), greater<ll>());

        ll ans = 0;
        for (int i = 0; i < k; ++i)
        {
            ans += min_val[i] + 1; // Đảm bảo 1 cặp cho màu này
        }
        for (int i = k; i < n; ++i)
        {
            ans += min_val[i]; // Không tạo thêm cặp
        }

        cout << ans << endl;
    }
    return 0;
}