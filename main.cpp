#include <bits/stdc++.h>
using namespace std;
#define newl "\n"
#define yes "YES"
#define int long long
#define no "NO"
#define deb(x)cout << (#x) << ": "; _p(x);
template <typename T>
void _p(T t) { cout << t; }

void solve(int test_case, int total_cases)
{
    int n;
    cin >> n;
    int k;cin>>k;
    if(k==n){
        for(int i = 0;i<n;i++){
            cout<<1<<" ";
        }
    }else if(k==1){
        for(int i = 0;i<n;i++){
            cout<<i+1<<" ";
        }
    }else{
        cout<<-1;
    }
    // deb(n)
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