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

void make_set(int v, vector<pair<int, int>> &parent)
{
    parent[v].first = v;
    parent[v].second++;
}
int find_root(int node, vector<pair<int, int>> &parent)
{
    if (node == parent[node].first)
        return node;
    return parent[node].first = find_root(parent[node].first, parent);
}

void join_roots(int a, int b, vector<pair<int, int>> &parent)
{
    a = find_root(a, parent);
    b = find_root(b, parent);
    if (a == b)
        return;
    if (parent[a].second < parent[b].second)
        swap(a, b);
    parent[b].first = parent[a].first;
    parent[a].second += parent[b].second;
}

int getSize(int root, vector<int> &sizes, vector<int> arr[], int parent)
{
    // deb(sizeof(arr));
    // for (auto i : sizes)
    // {
    //     cout << i << " ";
    // }
    // deb(root);
    // return 1;
    // root=2,3,4,5
    if (!sizes[root])
    {

        // 3,8
        int family_size = 0;
        for (auto i : arr[root])
        {
            // deb(i);
            if (i != parent)
            {
                family_size += getSize(i, sizes, arr, root);
            }
        }
        sizes[root] = family_size + 1;
    }
    return sizes[root];
}
int getLChild(int node, int par, vector<int> arr[])
{
    for (auto i : arr[node])
    {
        if (i != par)
        {
            return i;
        }
    }
}
int dfs(int node, int par, vector<int> &sizes, vector<int> arr[])
{
    if (arr[node].size() == 1)
    {
        return 0;
    }
    if (arr[node].size() == 2)
    {
        // deb(sizes[getLChild(node, par, arr)]);
        return sizes[getLChild(node, par, arr)] - 1;
    }
    int lchild = getLChild(node, par, arr);
    // deb(lchild);

    int rchild;
    for (auto i : arr[node])
    {
        if (i != par && i != lchild)
        {
            rchild = i;
        }
    }
    // deb(sizes[rchild]);
    return max((dfs(lchild, node, sizes, arr) + sizes[rchild] - 1), (dfs(rchild, node, sizes, arr) + sizes[lchild] - 1));
}
string p1 = "Ayush";
string p2 = "Ashish";
bool isLeaf(int x, vector<int> adj[])
{
    return (adj[x].size() - 1) <= 0;
}
int degree(int x, vector<int> adj[])
{
    return adj[x].size();
}