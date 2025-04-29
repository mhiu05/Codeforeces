#include <bits/stdc++.h>
using namespace std;
int check(long long a)
{
    long long can = sqrt(a);
    if (can * can == a)
        return 1;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        long long sum = 0;
        for (int &x : a)
        {
            cin >> x;
            sum += x;
        }
        if (check(sum))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}