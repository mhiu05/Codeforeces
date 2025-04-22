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

void solution_1(deque<ll> &dqNor, deque<ll> &dqRev, ll &sum, ll &score, ll &rscore)
{
    // Normal
    ll sizeNor = dqNor.size();
    ll a = dqNor.back();
    dqNor.pop_back();
    dqNor.push_front(a);
    score -= sizeNor * a;
    score += sum;
    // Reverse
    ll sizeRev = dqRev.size();
    ll b = dqRev.front();
    dqRev.pop_front();
    dqRev.push_back(b);
    rscore -= sum;
    rscore += sizeRev * b;
}

void solution_2(deque<ll> &dqNor, deque<ll> &dqRev, ll &score, ll &rscore)
{
    swap(dqNor, dqRev);
    swap(score, rscore);
}

void solution_3(deque<ll> &dqNor, deque<ll> &dqRev, ll &sum, ll &score, ll &rscore)
{
    ll k;
    cin >> k;
    dqNor.push_back(k);
    dqRev.push_front(k);
    sum += k;
    score += dqNor.size() * k;
    rscore += sum;
}

void solve()
{
    deque<ll> dqNor, dqRev;
    ll sum = 0, score = 0, rscore = 0;
    int q;
    cin >> q;
    while (q--)
    {
        int s;
        cin >> s;
        if (s == 1)
            solution_1(dqNor, dqRev, sum, score, rscore);
        else if (s == 2)
            solution_2(dqNor, dqRev, score, rscore);
        else
            solution_3(dqNor, dqRev, sum, score, rscore);
        cout << score << endl;
    }
}

int main()
{
    faster();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}