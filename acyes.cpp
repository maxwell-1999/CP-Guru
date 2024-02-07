#include <bits/stdc++.h>
using namespace std;
#define newl "\n"
#define deb(x) cout << (#x) << ":" << x << endl;
#define yes "YES"
#define int long long
#define no "NO"
void solve(int test_case, int total_cases)
{
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    vector<int> q(n);
    vector<int> A(n);
    vector<int> b(n);
    for (auto &i : q)
        cin >> i;
    for (auto &i : A)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int ub = *max_element(q.begin(), q.end());
    for (int a = 1; a < 1000001; a++)
    {
        int mn = INT64_MAX;
        for (int i = 0; i < n; i++)
        {
            int t = q[i] - A[i] * a;
            if (t < 0)
                goto END;
            if (b[i])
                mn = min(mn, t / b[i]);
        }
        ans = max(ans, a + mn);
    END:;
    }
    cout << ans;
}

// thinking 20
// implementing 13
// testing