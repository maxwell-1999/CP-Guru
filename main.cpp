#include <bits/stdc++.h>
using namespace std;
#define newl "\n"
// #define deb(x) ;
#define deb(x) cout << (#x) << ":" << x << endl;
#define yes "Yes";

#define yes "YES"
#define int long long
#define no "NO"
void solve(int test_case, int total_cases)
{
    // take input and construct color-pos 1m +2m
    int n, m;
    cin >> n >> m;
    map<int, vector<pair<int, int>>> arr;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            int temp;
            cin >> temp;
            arr[temp].push_back({row + 1, col + 1});
        }
    }
    // for each color two for loops for considering every case 2m +3m
    int ans = 0;
    for (auto &color : arr)
    {
        // deb(color);
        int len = color.second.size();
        for (int i = 0; i < len; i++)
        {
            for (int col = i + 1; col < len; col++)
            {
                // 1,2  3 4
                int dist = abs(color.second[i].first - color.second[col].first) + abs(color.second[i].second - color.second[col].second);
                ans += dist;
            }
        }
    }
    cout << ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{1};
    // cin >> t;
    int total_cases = t;
    while (t--)
    {
        solve(t + 1, total_cases);
        cout << newl;
    }
    return 0;
}

// 10:06