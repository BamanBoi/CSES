#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int>g[N];
bool vis[N]={false};
vector<int> v;
void dfs(int vertex){
    if (vis[vertex])
    {
        return;
    }

    vis[vertex]=true;
    v.push_back(vertex);
    for(auto child: g[vertex]){
        
        dfs(child);
        
    }
    
}
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = v.size()-1; i>=0; i--)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}