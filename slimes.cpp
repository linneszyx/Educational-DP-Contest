#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 400;
int n, arr[N], pref[N], memo[N][N];
int sum(int l, int r)
{
    return pref[r] - (l == 0 ? 0 : pref[l - 1]);
}
int dp(int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    int &ans = memo[l][r];
    if (ans != 0)
        return ans;
    ans = 1e18;
    for (int i = l; i < r; i++)
    {
        ans = min(ans, dp(l, i) + dp(i + 1, r) + sum(l, r));
    }
    return ans;
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
        cin >> arr[i];
        pref[i] = arr[i];
        if (i)
            pref[i] += pref[i - 1];
    }
    cout << dp(0, n - 1);
    return 0;
}