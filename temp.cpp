#include <bits/stdc++.h>
using namespace std;
#define newl "\n"
#define yes "YES"
#define int long long
#define no "NO"
#define deb(x) cout << (#x) << ": " << x << newl;
// #define deb(x) ;

int mod = 1000000007;
void solve(int test_case, int total_cases)
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    for (auto &i : arr)
    {
        cin >> i;
        mp[i]++;
    }
    int g = n;
    int contra = 0;
    for (auto ele : arr)
    {

        int alt = 0;
        // deb(contra);
        if (!mp.count(ele) || !mp[ele])
            continue;
        for (int i = 30; i >= 0; i--)
        {
            if (!(ele & (1LL << i)))
            {
                alt = alt | (1LL << i);
            }
        }
        if (mp.count(alt))
        {
            mp[ele]--;
            if (!mp[ele])
            {
                mp.erase(ele);
            }
            mp[alt]--;
            if (!mp[alt])
            {
                mp.erase(alt);
            }
            contra++;
        }
    }
    cout << n - contra;
    // cout << newl;
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