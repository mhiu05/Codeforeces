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
        int n;
        cin >> n;
        vector<int> v0, v1;
        map<int, int> mp0, mp1;
        for (int i = 1; i <= n; ++i)
        {
            int x, y;
            cin >> x >> y;
            if (y == 0)
            {
                v0.push_back(x);
                mp0[x]++;
            }
            else
            {
                v1.push_back(x);
                mp1[x]++;
            }
        }
        ll ans = 0;
        for (auto it : mp0)
        {
            if (mp1[it.first])
            {
                ans += v0.size() - 1 + v1.size() - 1;
            }
        }
        for (int i = 0; i < v0.size(); ++i)
        {
            if (v0[i] - 1 >= 0 && v0[i] + 1 <= n)
            {
                if (mp1[v0[i] - 1] && mp1[v0[i] + 1])
                {
                    ++ans;
                }
            }
        }
        for (int i = 0; i < v1.size(); ++i)
        {
            if (v1[i] - 1 >= 0 && v1[i] + 1 <= n)
            {
                if (mp0[v1[i] - 1] && mp0[v1[i] + 1])
                {
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}