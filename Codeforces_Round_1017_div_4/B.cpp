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
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        int left = 0, right = 0;
        while (m--)
        {
            if (left > l)
            {
                --left;
            }
            else if (right < r)
            {
                ++right;
            }
        }
        cout << left << " " << right << endl;
    }
    return 0;
}