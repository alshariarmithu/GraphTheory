#include <bits/stdc++.h>
using namespace std;

const int N = 105;
bool vis[N];
int col[N];
vector<int> g[N];
bool ok;

void dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            col[v] = col[u] ^ 1;
            dfs(v);
        }
        else
        {
            if (col[u] == col[v])
            {
                ok = false;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ok = true;
    dfs(1);
    if (ok)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}
