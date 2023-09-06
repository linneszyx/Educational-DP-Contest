#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k, mod = 1e9 + 7;
    cin >> n >> k;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i - 1][j] += dp[i - 1][j - 1];
        }
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i] > 0)
            {
                dp[i][j] -= dp[i - 1][j - arr[i] - 1];
            }
            dp[i][j] = ((dp[i][j] % mod) + mod) % mod;
        }
    }
    cout << dp[n][k];
    return 0;
}