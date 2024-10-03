#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> g[N];
int indeg[N], outdeg[N];
bool vis[N];

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        indeg[v]++;
        g[u].push_back(v);
    }
    vector<int> T;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            T.push_back(i);
            vis[i]=true;
        }
    }
    vector<int> ans;
    while (ans.size() < n)
    {
        int cur = T.back();
        T.pop_back();
        ans.push_back(cur);
        for (auto v : g[cur])
        {
            indeg[v]--;
            if(!vis[v] and indeg[v]==0)
            {
                T.push_back(v);
                vis[v]=true;
            }
        }
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
