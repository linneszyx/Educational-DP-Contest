#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e5;
int a[N][3], dp[N][3];
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = a[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = a[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = a[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    return 0;
}