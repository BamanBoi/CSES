#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int parent[N];
vector<int> g[N];
vector<bool> vis(N);
vector<int> ans(N, 1);
bool flag = 1;
void dfs(int src, int par)
{
    for (auto child : g[src])
    {
        if (child == par)
        {
            continue;
        }
        if (!vis[child])
        {
            vis[child]=1;
            if (ans[src] == 1)
            {
                ans[child] = ans[src] + 1;
            }
            else
            {
                ans[child] = ans[src] - 1;
            }
            dfs(child, src);
        }
        else
        {
            if (ans[src] == ans[child])
            {
                flag = 0;
            }
        }
    }
}
    int main()
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                dfs(i, 0);
            }
        }
        if(flag){
            for (int i = 1; i <=n; i++)
            {
                cout<<ans[i]<<" ";
            }
        }
        else{
            cout<<"IMPOSSIBLE";
        }
        return 0;
    }