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

void solve(int a[], int b[], int n, int k)
{
    int cnt = 0;
    vector<int> idx;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] != -1)
        {
            idx.push_back(i);
        }
    }
    if (idx.size() == 1)
    {
        if (a[idx[0]] + b[idx[0]] > (*min_element(a, a + n) + k) || a[idx[0]] + b[idx[0]] < *max_element(a, a + n))
        {
            cout << 0 << endl;
            return;
        }
        cout << 1 << endl;
        return;
    }
    else if (idx.size() > 1)
    {
        int tmp = a[idx[0]] + b[idx[0]];
        for (int i = 0; i < idx.size(); ++i)
        {
            if (a[idx[i]] + b[idx[i]] != tmp)
            {
                cout << 0 << endl;
                return;
            }
        }
        if (tmp > (*min_element(a, a + n) + k) || tmp < *max_element(a, a + n))
        {
            cout << 0 << endl;
            return;
        }
        else
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << *min_element(a, a + n) + k - *max_element(a, a + n) + 1 << endl;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n], b[n];
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;
        solve(a, b, n, k);
    }
    return 0;
}