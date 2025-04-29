#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // Các vị trí median tiềm năng nằm trong khoảng [left, right]
    int left = (n - k - 1) / 2;
    int right = (n + k) / 2;

    // Số lượng các vị trí khác nhau trong khoảng này
    cout << a[right] - a[left] + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}