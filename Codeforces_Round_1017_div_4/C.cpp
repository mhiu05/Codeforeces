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

int a[801][801];

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int mark[2 * 800 + 1] = {0};
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> a[i][j];
                mark[a[i][j]] = 1;
            }
        }
        vector<int> ans(2 * n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                ans[i + j] = a[i][j];
            }
        }
        int idx = -1;
        for (int i = 1; i <= 2 * n; ++i)
        {
            if (mark[i] == 0)
                idx = i;
        }
        for (int i = 1; i <= 2 * n; ++i)
        {
            if (ans[i] != 0)
                cout << ans[i] << " ";
            else
                cout << idx << " ";
        }
        cout << endl;
    }
    return 0;
}