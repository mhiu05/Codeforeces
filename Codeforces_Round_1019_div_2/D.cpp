#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1), depth(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int T = 0;
        while ((1 << T) < n)
            T++;
        int M = T + 1;
        for (int i = 1; i <= n; i++)
        {
            depth[i] = (a[i] == -1 ? M : a[i]);
        }
        vector<vector<int>> by_depth(M + 1);
        for (int i = 1; i <= n; i++)
        {
            by_depth[depth[i]].push_back(i);
        }
        deque<int> avail;
        for (int x = 1; x <= n; x++)
            avail.push_back(x);
        vector<int> p(n + 1, 0);

        for (int d = 1; d < M; d++)
        {
            // build list of survivors > d
            vector<int> surv;
            for (int e = d + 1; e <= M; e++)
            {
                for (int i : by_depth[e])
                    surv.push_back(i);
            }
            sort(surv.begin(), surv.end());
            vector<pair<int, int>> segs;
            int prev = 0;
            for (int idx : surv)
            {
                if (prev + 1 <= idx - 1)
                    segs.emplace_back(prev + 1, idx - 1);
                prev = idx;
            }
            if (prev < n)
                segs.emplace_back(prev + 1, n);

            for (auto [L, R] : segs)
            {
                vector<int> D;
                for (int i = L; i <= R; i++)
                {
                    if (depth[i] == d)
                        D.push_back(i);
                }
                int k = D.size();
                if (k == 0)
                    continue;
                vector<int> vals(k);
                if (d & 1)
                {
                    for (int i = 0; i < k; i++)
                    {
                        vals[i] = avail.back();
                        avail.pop_back();
                    }
                }
                else
                {
                    for (int i = 0; i < k; i++)
                    {
                        vals[i] = avail.front();
                        avail.pop_front();
                    }
                }
                bool inc;
                if (d & 1)
                {
                    if (L == 1)
                        inc = false;
                    else if (R == n)
                        inc = true;
                    else
                        inc = false;
                }
                else
                {
                    if (L == 1)
                        inc = true;
                    else if (R == n)
                        inc = false;
                    else
                        inc = true;
                }
                if (inc)
                {
                    sort(vals.begin(), vals.end());
                }
                else
                {
                    sort(vals.begin(), vals.end(), greater<int>());
                }
                sort(D.begin(), D.end());
                for (int i = 0; i < k; i++)
                {
                    p[D[i]] = vals[i];
                }
            }
        }

        int last = by_depth[M][0];
        p[last] = avail.front();
        for (int i = 1; i <= n; i++)
        {
            cout << p[i] << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
