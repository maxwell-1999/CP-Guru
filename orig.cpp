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
    dp.resize(k + 2, vi(n + 2, -1));
    arr.assign(n, 0);
    for (auto &i : arr)
        cin >> i;

    int ans = 0;
    if (arr[0] == 0)
    {
        for (int i = 1; i <= k; i++)
        {
            ans += rec(1, i);
            ans %= m;
        }
    }
    else
    {
        ans = rec(0, arr[0]);
    }
    for (auto drow : dp)
    {
        for (auto dcol : drow)
            cout << dcol << " ";
        cout << endl;
    }
    cout << ans;

    return 0;
}
