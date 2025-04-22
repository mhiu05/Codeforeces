#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string s;
        s.reserve(n);
        cin >> s;
        // make it 1-based
        s = "#" + s;

        // A[i] = 1 if there's a transition between i-1 and i
        vector<int> A(n + 2, 0);
        for (int i = 2; i <= n; i++)
        {
            A[i] = (s[i] != s[i - 1]);
        }

        // base cost without any reversal
        long long cost0 = n;
        for (int i = 2; i <= n; i++)
            cost0 += A[i];
        // initial move if first char is '1'
        cost0 += (s[1] == '1');

        int bestDelta = 0; // we look for the most negative delta

        // --- Case 1: l = 1, r = 1..n ---
        // delta(r) = (newRight - oldRight) + (newInit - oldInit)
        // oldRight = A[r+1], newRight = [s[1]!=s[r+1]] (if r<n)
        // oldInit = (s[1]=='1'), newInit = (s[r]=='1')
        for (int r = 1; r <= n; r++)
        {
            int delta = 0;
            if (r < n)
            {
                delta += (s[1] != s[r + 1]) - A[r + 1];
            }
            delta += (s[r] == '1') - (s[1] == '1');
            bestDelta = min(bestDelta, delta);
        }

        // --- Case 2: l > 1 ---
        // We'll maintain, for each of the 4 bit‑pairs P = (x,y) = (s[l-1], s[l]),
        // the minimum value of -A[l] seen so far among positions l <= current r.
        // Then for each r we compute
        //
        //    M = min_{P} {  [x!=s[r]] + [y!=s[r+1]]  +  minNegA[P] }
        //    f(r) = M - A[r+1]   (or f(n)=M if r==n)
        //
        // and keep bestDelta = min(bestDelta, f(r)).
        const int INF = 1 << 29;
        int minNegA[4] = {INF, INF, INF, INF};

        for (int r = 2; r <= n; r++)
        {
            // first ingest l = r into our buckets
            int x = s[r - 1] - '0';
            int y = s[r] - '0';
            int id = (x << 1) | y;
            minNegA[id] = min(minNegA[id], -A[r]);

            // now compute the best g(l,r) = [x!=s[r]] + [y!=s[r+1]] - A[l]
            // by looking at all 4 buckets
            int Mval = INF;
            if (r < n)
            {
                int sr = s[r] - '0';
                int sr1 = s[r + 1] - '0';
                for (int P = 0; P < 4; P++)
                {
                    int X = (P >> 1) & 1;
                    int Y = P & 1;
                    int d = (X != sr) + (Y != sr1) + minNegA[P];
                    Mval = min(Mval, d);
                }
                // finally subtract the old right‐boundary cost A[r+1]
                int f = Mval - A[r + 1];
                bestDelta = min(bestDelta, f);
            }
            else
            {
                // r == n: no right boundary
                int sr = s[r] - '0';
                for (int P = 0; P < 4; P++)
                {
                    int X = (P >> 1) & 1;
                    int d = (X != sr) + minNegA[P];
                    Mval = min(Mval, d);
                }
                bestDelta = min(bestDelta, Mval);
            }
        }

        cout << (cost0 + bestDelta) << "\n";
    }

    return 0;
}
