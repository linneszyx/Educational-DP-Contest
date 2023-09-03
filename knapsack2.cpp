#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 101;
int v[N], w[N], W, n, mW[N][100001], dp[N][100001];

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 100001; j++)
        {
            mW[i][j] = 1e13;
        }
    }
    dp[0][0] = 1;
    mW[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 100001; j++)
        {
            if (dp[i - 1][j])
            {
                dp[i][j] = 1;
                mW[i][j] = min(mW[i][j], mW[i - 1][j]);
            }
            if (j - v[i] >= 0 and dp[i - 1][j - v[i]] and
                mW[i - 1][j - v[i]] + w[i] <= W)
            {
                dp[i][j] = 1;
                mW[i][j] = min(mW[i][j], mW[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 100001; i++)
    {
        if (dp[n][i])
        {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}