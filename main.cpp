#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
using namespace std;
int dp[102][1000003];
 
int main()
{
  fast_io;
  ll t, n, m, x, i, j, k, q;
  // cin >> t;
  t = 1;
  auto start = std::chrono::high_resolution_clock::now();
 
  while (t--)
  {
    cin >> n >> x;
    vector<int> v(n + 10);
    fr(1, n + 1) cin >> v[i];
    sort(v.begin(),v.end());
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
      for (int sum = 0; sum <= x; sum++)
      {
        cnt++;
        if (sum == 0)
          dp[i][sum] = 1;
        else
        {
          int op1 = (v[i] > sum) ? 0 : dp[i][sum - v[i]];
          int op2 = (i == 1) ? 0 : dp[i - 1][sum];
          dp[i][sum] = (op1 + op2) % mod;
        }
      }
    }
    // cout << cnt << endl;
    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    // cout << (duration.count()) << endl;
 
    cout << dp[n][x];
  }
  return 0;
}