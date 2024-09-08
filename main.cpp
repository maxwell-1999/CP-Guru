// No other way & never give up.
#include<bits/stdc++.h>
using namespace std;
#define deb(x)cout<<#x<<": "<<x<<'\n';
int m =1e9+7;
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
 
int res;
vector<pair<int,int>> dp;
pair<int,int> dfs(int root, vvi& g,int p=-1){      
    vi subroots_with_edges,subroots_without_edges;
    int sum=0;
    for(auto& ch:g[root]){
        if(p==ch)   continue;
        auto v=dfs(ch,g,root);
        sum+=v.second;
        subroots_with_edges.push_back(v.second);
        subroots_without_edges.push_back(v.first);
    }   
    int sz=subroots_with_edges.size();
    int ans=0;
    // if include - sum(2's subtrees) + 2 + 4

    for(int i=0;i<subroots_with_edges.size();i++){
        // exclude it from sum with edge.
        int include = sum-subroots_with_edges[i]; 

        // include its childrens i.e wo edges.
        include += subroots_without_edges[i];
        ans=max(ans,1+include);
    }
    return {sum,ans};
}
void solve(){
    int n=1,m=0;
    string s;
    cin>>n;
    res=0;
    dp.assign(n,{0,0});
    int e=n-1;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=e;i++){
      int u,v; cin>>u>>v;
      u--,v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    // I can root it any point. let's root it at 0?
    auto ans = dfs(0,g);
    cout<<ans.first<<" "<<ans.second;
}
 
int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

/*!SECTION



5
1 2
1 3
3 4
3 5*/