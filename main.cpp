#include <bits/stdc++.h>
using namespace std;
#define newl "\n"
#define yes "YES"
#define int long long
#define no "NO"
int mod = 1000000007;

void solve(int test_case, int total_cases)
{
  int n, t;
  cin >> n >> t;
  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;
    sort(arr.begin(),arr.end());
  vector<int> dp(t + 1);
  dp[0] = 1;
  for (int i = 1; i <= t; i++)
  {
    int ways = 0;
    for (auto coin : arr)
    {
      if (coin <= i)
      {
        ways = (ways + dp[i - coin]) % mod;
      }else {
        break;
      }
    }
    dp[i] = ways;
  }
  cout << dp[t];
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t{1};
  // cin >> t;
  int total_cases = t;
  int s = 1;
  while (t--)
  {
    solve(s++, total_cases);
    cout << newl;
  }
  return 0;
}
