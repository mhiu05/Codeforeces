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
        int n, x;
        cin >> n >> x;
        if (x == 0)
        {
            for (int i = 1; i < n; ++i)
            {
                cout << i << " ";
            }
            cout << 0 << endl;
        }
        else if (x == n)
        {
            for (int i = 0; i < n; ++i)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < x; ++i)
            {
                cout << i << " ";
            }
            for (int i = x + 1; i <= n - 1; ++i)
            {
                cout << i << " ";
            }
            cout << x << endl;
        }
    }
    return 0;
}