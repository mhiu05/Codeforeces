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
        int x, y, k;
        cin >> x >> y >> k;
        if (((y + k - 1) / k) == ((x + k - 1) / k))
        {
            cout << ((y + k - 1) / k) + ((x + k - 1) / k) << endl;
        }
        else if (((y + k - 1) / k) > ((x + k - 1) / k))
        {
            cout << 2 * ((y + k - 1) / k) << endl;
        }
        else
            cout << 2 * ((x + k - 1) / k) - 1 << endl;
    }
    return 0;
}