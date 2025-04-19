#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
int subm(int a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}
int mul(int a, int b) { return int((ll)a * b % MOD); }
int power(int a, ll e)
{
    int r = 1;
    while (e)
    {
        if (e & 1)
            r = mul(r, a);
        a = mul(a, a);
        e >>= 1;
    }
    return r;
}

void fwht(vector<int> &a, bool inv)
{
    int n = a.size();
    for (int len = 1; len < n; len <<= 1)
    {
        for (int i = 0; i < n; i += len << 1)
        {
            for (int j = 0; j < len; ++j)
            {
                int u = a[i + j], v = a[i + j + len];
                a[i + j] = add(u, v);
                a[i + j + len] = subm(u, v);
            }
        }
    }
    if (inv)
    {
        int inv_n = power(n, MOD - 2);
        for (int &x : a)
            x = mul(x, inv_n);
    }
}

int prefix(int k, int t)
{
    if (t < 0)
        return 0;
    if (k == 0)
        return (t + 1) % MOD;
    int d = __builtin_ctz(k) + 1;
    ll full = (t + 1) >> d;
    ll res = full * (1LL << (d - 1));
    int rem = (t + 1) & ((1 << d) - 1);
    if (rem > (1 << (d - 1)))
        res += rem - (1 << (d - 1));
    res %= MOD;
    if (__builtin_parity(k >> d))
        res = (MOD - res) % MOD;
    return int(res);
}

inline int blockT(int k, int l, int r)
{
    int A = prefix(k, r);
    int B = prefix(k, l - 1);
    int x = A - B;
    if (x < 0)
        x += MOD;
    return x;
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
        int sz = 1 << m;
        // f_hat sẽ giữ f trong miền tần số
        vector<int> f_hat(sz, 1);

        // nhân dồn vào f_hat
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            for (int k = 0; k < sz; k++)
            {
                int t = blockT(k, l, r);
                f_hat[k] = mul(f_hat[k], t);
            }
        }

        // inverse FWHT để về domain g_x = f_x
        fwht(f_hat, true);

        // tính h = XOR_{x=0..2^m-1} ( f_x * 2^x mod MOD )
        int h = 0;
        for (int x = 0; x < sz; x++)
        {
            int gx = mul(f_hat[x], power(2, x));
            h ^= gx;
        }
        cout << h << "\n";
    }
    return 0;
}
