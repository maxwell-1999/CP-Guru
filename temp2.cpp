#include <bits/stdc++.h>
using namespace std;
#define newl "\n"
#define yes "YES"
#define int long long
#define no "NO"
#define deb(x) ;
// #ifdef false
#define deb(x)            \
    cout << (#x) << ": "; \
    _p(x);                \
    cout << endl
// #endif
template <typename T>
void _p(T t) { cout << t; }

template <typename T>
void _p(set<T> s)
{
    for (auto c : s)
    {
        cout << c << " ";
    }
    // cout<<endl;
}

void solve(int test_case, int total_cases)
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    vector<int> b(n);
    for (auto &i : b)
        cin >> i;
    pair<int, int> nxt{-1, -1};
    int prev = -1;
    bool ans = false;
    int i;
    for (i = 0; i < n; i++)
    {
        int curr = nxt.first != -1 && nxt.first <= i ? nxt.second : a[i];
        if (curr == b[i])
        {
            prev = curr;
        }
        else if (curr > b[i])
        {
            break;
        }
        else if (prev != b[i])
        {
            int idx = -1;
            for (int j = i; j < n; j++)
            {
                if (a[j] == b[i])
                {
                    idx = j;
                    break;
                }
            }
            if (idx == -1)
            {
                break;
            }
            nxt = {idx, b[i]};
        }
    }
    if (i == n)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{1};
    cin >> t;
    int total_cases = t;
    int s = 1;
    while (t--)
    {
        solve(s++, total_cases);
        cout << newl;
    }
    return 0;
}