#include <bits/stdc++.h>
using namespace std;
#define newl "\n"
#define deb(x) ;
// #define deb(x) cout << (#x) << ":" << x << endl;
#define yes "YES"
#define int long long
#define no "NO"
void solve(int test_case, int total_cases)
{
    int n, k;

    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    int amap[26] = {0};
    int bmap[26] = {0};
    for (auto i : a)
    {
        amap[i - 'a']++;
    }
    for (auto i : b)
    {
        bmap[i - 'a']++;
    }
    string sa = "";
    string ta = "";

    for (int i = 0; i < 26; i++)
    {
        if (amap[i] % k)
        {
            ta += string((amap[i] / k) * k, (char)(i + 'a'));
            sa += string(amap[i] % k, (char)(i + 'a'));
        }
        else
        {
            ta += string(amap[i], (char)(i + 'a'));
        }
    }
    // return;
    string sb = "";
    string tb = "";

    for (int i = 0; i < 26; i++)
    {
        if (bmap[i] % k)
        {
            tb += string((bmap[i] / k) * k, (char)(i + 'a'));
            sb += string(bmap[i] % k, (char)(i + 'a'));
        }
        else
        {
            tb += string(bmap[i], i + 'a');
        }
    }
    deb(sa);
    deb(sb);

    if (sa != sb)
    {
        cout << "NO";
        return;
    }
    deb(ta);
    deb(tb);
    for (int i = 0; i < tb.size();)
    {
        int diff = tb[i] - ta[i];

        if (diff < 0)
        {
            cout << no;
            return;
        }
        else if (diff)
        {
            int kcopy = k;
            char prev = ta[i];
            while (kcopy--)
            {
                if (i >= n)
                {
                    cout << no;
                    return;
                }
                if (ta[i] != prev || ((char)(ta[i] + diff) != tb[i]))
                {
                    cout << no;
                    return;
                }
                ta[i] += diff;
                i++;
            }
        }
        else
        {
            i++;
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

// thinking 20
// implementing 13
// testing
// aacddg
// aadddg

// aaggkzz
// aaggkzz