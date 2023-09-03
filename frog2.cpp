#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout << dp[n - 1];
    return 0;
}