#include <bits/stdc++.h>
using namespace std;
#define newl "\n"
#define yes "YES"
#define int long long
#define no "NO"
#define deb(x)          \
  cout << (#x) << ": "; \
  _p(x);                \
  cout << newl;
template <typename T>
void _p(T t) { cout << t; }
void _p(set<int> t)
{
  for (auto s : t)
    cout << s << " ";
}

void solve(int test_case, int total_cases)
{
  int a = -2LL;
  cout << __builtin_popcountll(a);
}
signed main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // time_t start, end;
  // time(&start);

  int t{1};
  // cin >> t;
  int total_cases = t;
  int s = 1;
  while (t--)
  {
    solve(s++, total_cases);
    cout << newl;
  }
  // time(&end);
  // double time_taken = double(end - start);
  // cout << fixed
  //      << time_taken << setprecision(5) << " secs";
  return 0;
}