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
        ll k;
        cin >> n >> k;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (n < 3)
        {
            cout << "NO\n";
            continue;
        }

        // build prefix‐sum of xi = +1 if a[i]<=k, else -1
        vector<ll> P(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            P[i] = P[i - 1] + (a[i] <= k ? +1 : -1);
        }

        // suffixMax[p][i] = max P[j] over j in [i..n-1] with j%2==p
        const ll INF_LL = (ll)4e18;
        vector<ll> suffixMax0(n + 2, -INF_LL), suffixMax1(n + 2, -INF_LL);
        for (int i = n - 1; i >= 1; i--)
        {
            suffixMax0[i] = suffixMax0[i + 1];
            suffixMax1[i] = suffixMax1[i + 1];
            if ((i & 1) == 0)
                suffixMax0[i] = max(suffixMax0[i], P[i]);
            else
                suffixMax1[i] = max(suffixMax1[i], P[i]);
        }

        // prefixMin[p][i] = min P[j] over j in [1..i] with j%2==p
        vector<ll> prefixMin0(n + 1, +INF_LL), prefixMin1(n + 1, +INF_LL);
        for (int i = 1; i <= n; i++)
        {
            prefixMin0[i] = prefixMin0[i - 1];
            prefixMin1[i] = prefixMin1[i - 1];
            if ((i & 1) == 0)
                prefixMin0[i] = min(prefixMin0[i], P[i]);
            else
                prefixMin1[i] = min(prefixMin1[i], P[i]);
        }

        // good1[i] = (median([1..i]) <= k)
        // good3[r] = (median([r+1..n]) <= k)
        vector<char> good1(n + 1, 0), good3(n + 1, 0);
        for (int i = 1; i <= n - 2; i++)
        {
            // segment [1..i] has length i,
            // needs P[i] >= ceil(i/2) → since sum xi = 2*c - i,
            // ceil(i/2) condition ⇔ sum xi ≥ (i%2)
            ll thr = (i & 1);
            if (P[i] >= thr)
                good1[i] = 1;
        }
        for (int r = 2; r <= n - 1; r++)
        {
            int len3 = n - r;
            ll thr = (len3 & 1);
            if (P[n] - P[r] >= thr)
                good3[r] = 1;
        }

        bool ok = false;

        // --- Case A: segments 1 & 3 are good ---
        // find earliest l with good1[l], latest r with good3[r]
        int l0 = -1, r0 = -1;
        for (int i = 1; i <= n - 2; i++)
            if (good1[i])
            {
                l0 = i;
                break;
            }
        for (int i = n - 1; i >= 2; i--)
            if (good3[i])
            {
                r0 = i;
                break;
            }
        if (l0 != -1 && r0 != -1 && l0 < r0)
        {
            ok = true;
        }

        // --- Case B: segments 1 & 2 are good ---
        if (!ok)
        {
            // for each l, try to find r>l so that both [1..l] and [l+1..r] are good
            for (int l = 1; l <= n - 2; l++)
                if (good1[l])
                {
                    int p = l & 1; // parity of l
                    ll base = P[l];
                    // segment2 [l+1..r] length parity = (r-l)&1
                    // if (r%2 == l%2) → even-length → need P[r] >= base
                    // if (r%2 != l%2) → odd-length  → need P[r] >= base+1
                    ll mx_same = (p == 0 ? suffixMax0[l + 1] : suffixMax1[l + 1]);
                    if (mx_same >= base)
                    {
                        ok = true;
                        break;
                    }
                    ll mx_opp = (p == 0 ? suffixMax1[l + 1] : suffixMax0[l + 1]);
                    if (mx_opp >= base + 1)
                    {
                        ok = true;
                        break;
                    }
                }
        }

        // --- Case C: segments 2 & 3 are good ---
        if (!ok)
        {
            // for each r, try to find l<r so that both [l+1..r] and [r+1..n] are good
            for (int r = 2; r <= n - 1; r++)
                if (good3[r])
                {
                    int p = r & 1; // parity of r
                    ll Pr = P[r];
                    // check seg2 = [l+1..r]:
                    //   if l%2 == r%2 → even → need Pr >= P[l]
                    //   else           → odd  → need Pr >= P[l]+1
                    ll mn_same = (p == 0 ? prefixMin0[r - 1] : prefixMin1[r - 1]);
                    if (mn_same <= Pr)
                    {
                        ok = true;
                        break;
                    }
                    ll mn_opp = (p == 0 ? prefixMin1[r - 1] : prefixMin0[r - 1]);
                    if (mn_opp <= Pr - 1)
                    {
                        ok = true;
                        break;
                    }
                }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
