/*
    Author : linneszyx
The only true fear is the fear of the unknown
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define forn(i, e) for (int i = 0; i < e; i++)
#define forsn(i, s, e) for (int i = s; i < e; i++)
#define rforn(i, s) for (int i = s; i >= 0; i--)
#define rforsn(i, s, e) for (int i = s; i >= e; i--)
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define print(a)      \
  for (auto x : a)    \
    cout << x << " "; \
  cout << endl
#define print1(a)  \
  for (auto x : a) \
  cout << x.F << " " << x.S << endl
#define print2(a, x, y)       \
  for (int i = x; i < y; i++) \
    cout << a[i] << " ";      \
  cout << endl
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int fact[N];
int addm(int x, int y)
{
  return (x + y) % mod;
}
int subm(int x, int y)
{
  return ((x - y) % mod + mod) % mod;
}
int mulm(int x, int y)
{
  return (x * y) % mod;
}
int powr(int x, int y)
{
  int res = 1;
  while (y)
  {
    if (y & 1)
      res = mulm(res, x);
    y >>= 1;
    x = mulm(x, x);
  }
  return res;
}
int inv(int x)
{
  return powr(x, mod - 2);
}
void calcfact()
{
  fact[0] = 1;
  for (int i = 1; i < N; i++)
    fact[i] = mulm(fact[i - 1], i);
}
int divison(int x, int y)
{
  return mulm(x, inv(y));
}
int ncr(int n, int r)
{
  return mulm(mulm(fact[N], inv(fact[r])), inv(fact[n - r]));
}
int npr(int n, int r)
{
  return mulm(fact[n], inv(fact[n - r]));
}
int n;
string str;
void waiffuu()
{
  cin >> n >> str;
  int dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  dp[n][0] = 1;
  int ans = 0;
  for (int i = n - 1; i > 0; i--)
  {
    for (int j = 1; j <= n; j++)
    {
      dp[i + 1][j] += dp[i + 1][j - 1];
    }
    for (int s = 0; s <= n; s++)
    {
      int g = (n - i - s);
      if (g < 0)
        continue;
      if (str[i - 1] == '<')
      {
        dp[i][s] = dp[i + 1][s + g - 1] - (s == 0 ? 0 : dp[i + 1][s - 1]);
      }
      else
      {
        dp[i][s] = dp[i + 1][s - 1];
      }
      dp[i][s] %= mod;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    ans += dp[1][i - 1];
    ans %= mod;
  }
  ans += mod;
  ans %= mod;
  cout << ans;
}

int32_t main()
{
  fast_cin();
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t = 1;
  //	cin >> t;
  while (t--)
    waiffuu();
  return 0;
}