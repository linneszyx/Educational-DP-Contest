#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 3000;
string s, t, res;
int n, m, memo[N][N];
int give_lcs(int i, int j)
{
    int &ans = memo[i][j];
    if (i == n || j == m)
        return 0;
    if (ans != -1)
        return ans;
    if (s[i] == t[j])
        ans = give_lcs(i + 1, j + 1) + 1;

    else
        ans = max(give_lcs(i + 1, j), give_lcs(i, j + 1));
    return ans;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> s >> t;
    n = s.size();
    m = t.size();
    memset(memo, -1, sizeof(memo));
    int l = give_lcs(0, 0);
    cout << l << endl;
    return 0;
}