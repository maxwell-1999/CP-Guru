#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, m, ali;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        if (n < m)
        {
            cout << n << endl;
            continue;
        }
        ali = 0;
        for (ll i = 1; i * i <= m; i++)
        {
            if (m % i)
                continue;
            if (i != 1)
            {
                ll k = n;
                while (!(k % m))
                    k /= i;
                ali = max(ali, k);
            }
            ll k = n;
            while (!(k % m))
                k /= m / i;
            ali = max(ali, k);
        }
        cout << ali << '\n';
    }
    return 0;
}