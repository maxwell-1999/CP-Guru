#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  ll n;
  cin >> n;

  vector<ll> a(n);

  map<ll, ll> mp;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll ans = 0;
  vector<ll> left(n, 0);
  ll mx = a[0], k = 1;
  ll r = n - 2;

  for (int i = 1; i < n; i++)
  {
    left[i] = mx + k + r--;
    if (mx + k < a[i])
    {
      mx = a[i];
      k = 1;
    }
    else
      k++;
  }
  // for(int i=0;i<n;i++)
  // cout<<left[i]<<" ";
  // cout<<"\n";
  vector<ll> right(n, 0);
  r = n - 2;
  mx = a[n - 1], k = 1;
  for (int i = n - 2; i >= 0; i--)
  {
    right[i] = mx + k + r--;
    if (mx + k < a[i])
    {
      mx = a[i];
      k = 1;
    }
    else
      k++;
  }
  // for(int i=0;i<n;i++)
  // cout<<right[i]<<" ";
  // cout<<"\n";
  ans = 1e19;
  for (int i = 0; i < n; i++)
  {
    // ans = max(ans, a[i]);

    //  ans= max(ans, left[i]);

    ans = min(ans, max({left[i], a[i], right[i]}));
  }

  // if(mp[ans] == 1) ans--;
  cout << ans << "\n";
}

int main()
{
  ll t = 1;
  // cin>>t;

  while (t--)
    solve();

  return 0;
}