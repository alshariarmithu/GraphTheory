#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> g[N];
int dep[N];

void dfs(int u, int p)
{
    dep[u] = dep[p] + 1;
    for (auto v : g[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++)
    {
        cout<<dep[i]<<' ';
    }
    return 0;
}
