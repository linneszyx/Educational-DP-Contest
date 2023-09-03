#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 100;
int v[N], w[N], W, n, memo[N][100001];
int knapsack(int index, int weight)
{
    if (index >= n)
    {
        return 0;
    }
    int &ans = memo[index][weight];
    if (ans != -1)
    {
        return ans;
    }
    ans = knapsack(index + 1, weight);
    if (w[index] + weight <= W)
    {
        ans = max(ans, v[index] + knapsack(index + 1, weight + w[index]));
    }
    return ans;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << knapsack(0, 0);
    return 0;
}