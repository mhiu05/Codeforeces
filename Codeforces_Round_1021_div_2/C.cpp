#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll &x : a)
            cin >> x;
        sort(a.begin(), a.end());

        // RLE: u = unique days, c = counts
        vector<ll> u;
        vector<int> c;
        for (int i = 0; i < n;)
        {
            ll d = a[i];
            int cnt = 0;
            while (i < n && a[i] == d)
            {
                ++cnt;
                ++i;
            }
            u.push_back(d);
            c.push_back(cnt);
        }

        bool ok = false;
        int m = u.size();

        // 1) Có ngày nào cược >= 4 lần
        for (int i = 0; i < m; i++)
        {
            if (c[i] >= 4)
            {
                ok = true;
                break;
            }
        }

        // 2) Có hai ngày liên tiếp (d, d+1), mỗi ngày cược >= 2 lần
        if (!ok)
        {
            for (int i = 0; i + 1 < m; i++)
            {
                if (u[i + 1] == u[i] + 1 && c[i] >= 2 && c[i + 1] >= 2)
                {
                    ok = true;
                    break;
                }
            }
        }

        // 3) Có ba ngày liên tiếp (d, d+1, d+2) với mô hình cược 2–1–2
        if (!ok)
        {
            for (int i = 0; i + 2 < m; i++)
            {
                if (u[i + 1] == u[i] + 1 && u[i + 2] == u[i] + 2 && c[i] >= 2 && c[i + 1] >= 1 && c[i + 2] >= 2)
                {
                    ok = true;
                    break;
                }
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
