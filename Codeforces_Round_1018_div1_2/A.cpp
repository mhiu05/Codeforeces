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
        string s;
        cin >> s;
        vector<int> ans(n + 1, 0);
        int mark[105] = {0};
        int smaller = 1, larger = n;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == '<')
            {
                ans[i + 2] = smaller;
                mark[smaller] = 1;
                ++smaller;
            }
            else
            {
                ans[i + 2] = larger;
                mark[larger] = 1;
                --larger;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (mark[i] == 0)
                cout << i << " ";
        }
        for (int i = 2; i <= n; ++i)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}