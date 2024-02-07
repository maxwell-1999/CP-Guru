#include <bits/stdc++.h>
using namespace std;
#define newl "\n"
#define yes "YES"
#define int long long
#define no "NO"

void solve(int test_case, int total_cases)
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int idx = 0;
    vector<int> scnt(3);
    vector<int> tcnt(3);
    while (idx < n)
    {
        if (t[idx] == 'a' || s[idx] == 'a')
        {
            if (scnt[2] != tcnt[2])
            {
                cout << no;
                return;
            }
        }
        if (t[idx] == 'c' || s[idx] == 'c')
        {
            if (scnt[0] != tcnt[0])
            {
                cout << no;
                return;
            }
        }
        scnt[s[idx] - 'a']++;
        tcnt[s[idx] - 'a']++;
        idx++;
    }
    for (int i = 0; i < 3; i++)
    {
        if (scnt[i] != tcnt[i])
        {
            cout << no;
            return;
        }
    }
    cout << yes;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{1};
    cin >> t;
    int total_cases = t;
    while (t--)
    {
        solve(t + 1, total_cases);
        cout << newl;
    }
    return 0;
}