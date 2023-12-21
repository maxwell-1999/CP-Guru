#include <bits/stdc++.h>
using namespace std;
#define newl "\n"
#define deb(x) cout << (#x) << ":" << x << endl;
#define yes "Yes";
#define int long long
#define no "No";
void solve(int test_case)
{

    int n, m;
    cin >> n >> m;

    vector<int> rowsacc(n);
    vector<int> colsacc(m);
    vector<string> vs(n);
    for (auto &ele : vs)
        cin >> ele;
    // rowsacc
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (vs[row][col] == 'U')
            {
                rowsacc[row]++;
            }
        }
        if (rowsacc[row] & 1)
        {
            cout << -1 << newl;
            return;
        }
    }
    // colsacc
    for (int col = 0; col < m; col++)
    {
        for (int row = 0; row < n; row++)
        {
            if (vs[row][col] == 'L')
            {
                colsacc[col]++;
            }
        }
        if (colsacc[col] & 1)
        {
            cout << -1 << newl;
            return;
        }
    }

    // row wise traversal, fill u,d as W,B
    for (int row = 0; row < n; row++)
    {
        int half = rowsacc[row] / 2;
        if (!half)
            continue;
        for (int col = 0; col < m; col++)
        {
            if (vs[row][col] == 'U')
            {
                bool w = half <= 0 ? false : true;
                vs[row][col] = w ? 'W' : 'B';
                vs[row + 1][col] = !w ? 'W' : 'B';
                half--;
            }
        }
    }
    // col wise traversal, fill l,r as W,B
    for (int col = 0; col < m; col++)
    {
        int half = colsacc[col] / 2;
        if (!half)
            continue;
        for (int row = 0; row < n; row++)
        {
            if (vs[row][col] == 'L')
            {
                bool w = half <= 0 ? false : true;
                vs[row][col] = w ? 'W' : 'B';
                vs[row][col + 1] = !w ? 'W' : 'B';
                half--;
            }
        }
    }
    for (auto ele : vs)
        cout << ele << newl;
    // for (auto ele : rowsacc)
    //     cout << ele << " ";
    // cout << newl;
    // for (auto ele : colsacc)
    //     cout << ele << " ";
}
signed main()
{
    int t{1};
    cin >> t;
    while (t--)
    {
        solve(t + 1);
        // cout << newl;
    }
    return 0;
}

// 10:06