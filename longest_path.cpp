#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e5 + 1;
int memo[N];
vector<int> gr[N];
int dp(int curr)
{
    int &ans = memo[curr];
    if (ans != -1)
        return ans;
    ans = 0;
    for (auto x : gr[curr])
    {
        ans = max(ans, dp(x) + 1);
    }
    return ans;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
    }
    memset(memo, -1, sizeof(memo));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp(i));
    }
    cout << ans << endl;
    return 0;
}