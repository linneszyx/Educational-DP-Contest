#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 3001;
int n, a[N], sum = 0;
int memo[N][N][2];
int dp(int i, int j)
{
    if (i == j)
        return a[i];
    return max(a[i] - dp(i + 1, j), a[j] - dp(i, j - 1));
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << dp(0, n - 1);
    return 0;
}