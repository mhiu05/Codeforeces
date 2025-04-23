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
const int MAXN = 100005;

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll c = n * (2 * k + n - 1) / 2;
        double delta = (2.0 * k - 1) * (2.0 * k - 1) + 4.0 * c;
        double x = (-1.0 * (2 * k - 1) + sqrt(delta)) / 2;
        ll i = floor(x);
        cout << min(abs(c - i * (2 * k + i - 1)), abs(c - (i + 1) * (2 * k + (i + 1) - 1))) << endl;
    }
    return 0;
}