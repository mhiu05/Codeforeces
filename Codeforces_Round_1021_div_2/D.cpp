#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1'000'000'007;

// safe add/mul
inline int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
inline int mul(ll a, ll b) { return int((a * b) % MOD); }

// encode a grid cell (x,y) into a single integer ID
inline int encode(int x, int y, int m)
{
    return (x - 1) * m + (y - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int, int>> odd(k + 1);
        for (int i = 0; i <= k; i++)
        {
            cin >> odd[i].first >> odd[i].second;
        }

        // we'll build for each of the k segments the list of possible even-cell IDs
        // S[i] will have size 0,1 or 2
        vector<array<int, 2>> S_id(k);
        vector<int> S_sz(k);

        bool possible = true;
        const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < k; i++)
        {
            int x1 = odd[i].first, y1 = odd[i].second;
            int x2 = odd[i + 1].first, y2 = odd[i + 1].second;

            // collect neighbors of p1
            vector<pair<int, int>> N1;
            for (int d = 0; d < 4; d++)
            {
                int nx = x1 + dx[d], ny = y1 + dy[d];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
                    N1.emplace_back(nx, ny);
            }
            // collect neighbors of p2 in an unordered_set
            unordered_set<int> N2;
            N2.reserve(4);
            for (int d = 0; d < 4; d++)
            {
                int nx = x2 + dx[d], ny = y2 + dy[d];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
                    N2.insert(encode(nx, ny, m));
            }

            // intersect
            S_sz[i] = 0;
            for (auto &p : N1)
            {
                int id = encode(p.first, p.second, m);
                if (N2.count(id))
                {
                    S_id[i][S_sz[i]++] = id;
                    if (S_sz[i] == 2)
                        break; // at most 2
                }
            }
            if (S_sz[i] == 0)
            {
                possible = false;
                break;
            }
        }

        if (!possible)
        {
            cout << 0 << "\n";
            continue;
        }

        // DP: prev_dp[j] = ways to choose S_{i-1}[j]
        vector<int> prev_dp(S_sz[0], 1), cur_dp;
        // iterate segments 1..k-1
        for (int i = 1; i < k; i++)
        {
            cur_dp.assign(S_sz[i], 0);
            // for each choice j in S_i
            for (int j = 0; j < S_sz[i]; j++)
            {
                ll sum = 0;
                int idj = S_id[i][j];
                for (int p = 0; p < S_sz[i - 1]; p++)
                {
                    // only if not reusing the same cell
                    if (idj != S_id[i - 1][p])
                    {
                        sum += prev_dp[p];
                        if (sum >= MOD)
                            sum -= MOD;
                    }
                }
                cur_dp[j] = int(sum);
            }
            swap(prev_dp, cur_dp);
        }

        // answer = sum of ways for the last segment
        int ans = 0;
        for (int v : prev_dp)
            ans = add(ans, v);

        cout << ans << "\n";
    }
    return 0;
}
