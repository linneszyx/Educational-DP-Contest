#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dp[k + 1];
    dp[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (i - a[j] >= 0 and dp[i - a[j]] == 0)
            {
                dp[i] = 1;
                break;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second");
    return 0;
}