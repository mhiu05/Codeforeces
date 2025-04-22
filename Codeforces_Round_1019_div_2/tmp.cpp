#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll M = ((ll)1 << k) - 1;
        int W = k + 2; // xét tối đa k+2 về mỗi bên
        vector<ll> ans(n);

        for (int i = 0; i < n; i++)
        {
            ll best = a[i];
            // l chạy từ i về tối đa W-1 bước
            int l0 = max(0, i - (W - 1));
            for (int l = i; l >= l0; l--)
            {
                // tính nor của [l..i]
                ll cur = a[l];
                for (int j = l + 1; j <= i; j++)
                {
                    cur = (~(cur | a[j])) & M;
                }
                best = max(best, cur);

                // rồi mở rộng [l..r] thêm về phải tối đa W-1 bước
                ll temp = cur;
                int r1 = min(n - 1, i + (W - 1));
                for (int r = i + 1; r <= r1; r++)
                {
                    temp = (~(temp | a[r])) & M;
                    best = max(best, temp);
                }
            }
            ans[i] = best;
        }

        // xuất kết quả
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
