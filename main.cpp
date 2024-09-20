#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ": " << x << '\n';
int m = 1e9 + 7;
#define vi vector<int>
vi arr;
int k;
vector<vi> dp;
int cache(int i, int j, int set = -1)
{
  if (set != -1)
    return dp[j + 1][i] = set;
  return dp[j + 1][i];
}
int rec(int lvl, int prev)
{
  // deb(lvl);
  if (lvl == arr.size())
  {
    return 1;
  }
  int ans = 0;
  if (cache(lvl, prev) != -1)
    return cache(lvl, prev);
  if (arr[lvl] && abs(arr[lvl] - prev) > 1)
  {
    ans = 0;
  }
  else if (arr[lvl] != 0)
  {
    ans = rec(lvl + 1, arr[lvl]);
  }
  else
  {
    ans += rec(lvl + 1, prev) % m;
    ans %= m;
    if (prev != 1)
      ans += rec(lvl + 1, prev - 1) % m;
    ans %= m;
    if (prev != k)
      ans += rec(lvl + 1, prev + 1) % m;
    ans %= m;
  }
  return cache(lvl, prev, ans);
}

int main()
{
  int n;
  cin >> n >> k;
  dp.resize(k + 1, vi(n + 1, 0));
  arr.assign(n, 0);
  for (auto &i : arr)
    cin >> i;

  for (int row = k; row >= 0; row--)
  {
    dp[row][n] = 1;
  }
  int ans = 0;
  for (int colaslvl = n - 1; colaslvl >= 0; colaslvl--)
  {
    for (int rowask = 1; rowask <= k; rowask++)

    {
      ans = 0;
      if (arr[colaslvl] && abs(arr[colaslvl] - rowask) > 1)
      {
        ans = 0;
      }
      else if (arr[colaslvl] != 0)
      {
        ans = dp[arr[colaslvl]][colaslvl + 1];
        // cout << "got " << rowask << " " << colaslvl << endl;
      }
      else
      {
        ans += dp[rowask][colaslvl + 1] % m;
        ans %= m;
        if (rowask != 1)
          ans += dp[rowask - 1][colaslvl + 1] % m;
        ans %= m;
        if (rowask != k)
          ans += dp[rowask + 1][colaslvl + 1] % m;
        ans %= m;
      }

      dp[rowask][colaslvl] = ans;
    }
  }
  ans = 0;
  if (arr[0] == 0)
  {
    for (int i = 1; i <= k; i++)
    {
      ans += dp[i][1];
      ans %= m;
    }
  }
  else
  {
    ans = dp[arr[0]][0];
  }
  cout << ans;

  return 0;
}
