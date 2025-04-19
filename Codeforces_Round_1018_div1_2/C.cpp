#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

int t, n;
vector<vector<int>> h;
vector<int> a, b;

int solve()
{
    vector<vector<pair<int, int>>> graph(n * 2); // r[0..n-1], c[0..n-1] → total 2n nodes
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - 1; ++j)
        {
            if (h[i][j] == h[i][j + 1])
            {
                // r[i] + c[j] ≠ r[i] + c[j+1] ⇒ c[j] ≠ c[j+1]
                graph[n + j].emplace_back(n + j + 1, 1);
                graph[n + j + 1].emplace_back(n + j, 1);
            }
        }

    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (h[i][j] == h[i + 1][j])
            {
                // r[i] + c[j] ≠ r[i+1] + c[j] ⇒ r[i] ≠ r[i+1]
                graph[i].emplace_back(i + 1, 1);
                graph[i + 1].emplace_back(i, 1);
            }
        }

    vector<int> color(2 * n, -1);
    int total_cost = 0;

    for (int v = 0; v < 2 * n; ++v)
    {
        if (color[v] != -1)
            continue;

        // Try 2 possibilities: v = 0 and v = 1
        int cost0 = 0, cost1 = 0;
        bool ok0 = true, ok1 = true;
        queue<int> q;

        // Try color[v] = 0
        vector<int> c0(2 * n, -1);
        c0[v] = 0;
        q.push(v);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto [nei, w] : graph[u])
            {
                int expected = c0[u] ^ w;
                if (c0[nei] == -1)
                {
                    c0[nei] = expected;
                    q.push(nei);
                }
                else if (c0[nei] != expected)
                {
                    ok0 = false;
                    break;
                }
            }
            if (!ok0)
                break;
        }

        if (ok0)
        {
            for (int i = 0; i < n; ++i)
                if (c0[i] == 1)
                    cost0 += a[i];
            for (int i = 0; i < n; ++i)
                if (c0[n + i] == 1)
                    cost0 += b[i];
        }
        else
        {
            cost0 = INF;
        }

        // Try color[v] = 1
        vector<int> c1(2 * n, -1);
        c1[v] = 1;
        q.push(v);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto [nei, w] : graph[u])
            {
                int expected = c1[u] ^ w;
                if (c1[nei] == -1)
                {
                    c1[nei] = expected;
                    q.push(nei);
                }
                else if (c1[nei] != expected)
                {
                    ok1 = false;
                    break;
                }
            }
            if (!ok1)
                break;
        }

        if (ok1)
        {
            for (int i = 0; i < n; ++i)
                if (c1[i] == 1)
                    cost1 += a[i];
            for (int i = 0; i < n; ++i)
                if (c1[n + i] == 1)
                    cost1 += b[i];
        }
        else
        {
            cost1 = INF;
        }

        if (min(cost0, cost1) == INF)
            return -1;

        // Apply the best coloring
        if (cost0 <= cost1)
        {
            total_cost += cost0;
            for (int i = 0; i < 2 * n; ++i)
                if (c0[i] != -1)
                    color[i] = c0[i];
        }
        else
        {
            total_cost += cost1;
            for (int i = 0; i < 2 * n; ++i)
                if (c1[i] != -1)
                    color[i] = c1[i];
        }
    }

    return total_cost;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--)
    {
        cin >> n;
        h.assign(n, vector<int>(n));
        a.resize(n);
        b.resize(n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> h[i][j];

        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        cout << solve() << '\n';
    }

    return 0;
}