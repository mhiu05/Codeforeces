#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n + 1), b;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        b = a;
        sort(b.begin() + 1, b.end());

        ll mn = *min_element(a.begin() + 1, a.end());
        ll mx = *max_element(a.begin() + 1, a.end());
        if (mn + mx > k)
        {
            cout << -1 << "\n";
            continue;
        }

        // build map from value -> set of indices
        unordered_map<ll, set<int>> pos;
        pos.reserve(n * 2);
        for (int i = 1; i <= n; i++)
        {
            pos[a[i]].insert(i);
        }

        vector<array<ll, 3>> ops;
        ops.reserve(n);

        // process each position
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == b[i])
                continue;
            ll delta = a[i] - b[i];
            if (delta > 0)
            {
                // need to decrease a[i] by delta
                ll want = k - a[i];
                auto &S = pos[want];
                // pick any j != i
                int j = -1;
                for (int idx : S)
                {
                    if (idx != i)
                    {
                        j = idx;
                        break;
                    }
                }
                // perform op (i, j, x=delta)
                ops.push_back({i, j, delta});
                // update pos
                pos[a[i]].erase(i);
                pos[a[j]].erase(j);
                a[i] -= delta;
                a[j] += delta;
                pos[a[i]].insert(i);
                pos[a[j]].insert(j);
            }
            else
            {
                // delta < 0: need to increase a[i] by -delta
                ll need = -delta;
                ll want = k - a[i]; // note: original a[i]
                auto &S = pos[want];
                int j = -1;
                for (int idx : S)
                {
                    if (idx != i)
                    {
                        j = idx;
                        break;
                    }
                }
                // perform op (j, i, x=need)
                ops.push_back({j, i, need});
                pos[a[j]].erase(j);
                pos[a[i]].erase(i);
                a[j] -= need;
                a[i] += need;
                pos[a[j]].insert(j);
                pos[a[i]].insert(i);
            }
        }

        // output
        cout << ops.size() << "\n";
        for (auto &t : ops)
        {
            cout << t[0] << " " << t[1] << " " << t[2] << "\n";
        }
    }
    return 0;
}
