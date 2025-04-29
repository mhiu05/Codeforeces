#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define sec second
#define endl "\n"
#define faster ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int mod = 1e9 + 7;
const int MAXN = 100005;

int main()
{
    faster;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            b[i] = a[i] - i;
        }

        map<int, int> mp;   // lưu số lần xuất hiện của b[i]
        map<int, int> freq; // lưu số lượng các tần suất
        vector<int> ans;

        for (int i = 1; i <= k; ++i)
        {
            freq[mp[b[i]]]--;
            mp[b[i]]++;
            freq[mp[b[i]]]++;
        }

        int l = 1, r = k;
        ans.push_back(freq.rbegin()->first); // tần suất lớn nhất ban đầu

        while (r < n)
        {
            // Xóa b[l]
            freq[mp[b[l]]]--;
            if (freq[mp[b[l]]] == 0)
                freq.erase(mp[b[l]]);
            mp[b[l]]--;
            if (mp[b[l]] > 0)
                freq[mp[b[l]]]++;

            // Thêm b[++r]
            ++r;
            freq[mp[b[r]]]--;
            if (freq[mp[b[r]]] == 0)
                freq.erase(mp[b[r]]);
            mp[b[r]]++;
            freq[mp[b[r]]]++;

            ++l;

            ans.push_back(freq.rbegin()->first); // tần suất lớn nhất
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << k - ans[l - 1] << "\n";
        }
    }
    return 0;
}
