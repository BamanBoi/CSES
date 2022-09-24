#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
vector<int>g[N];
vector<bool> vis(N);
int ans=0;
void dfs(int src,int par=-1){
    for(auto child:g[src]){
        if(child==par){
            continue;
        }
        dfs(child,src);
    }
    if(par==-1){
        return;
    }
    if(vis[src]!=true && vis[par]!=true){
         
         ans++;
         vis[src]=vis[par]=true;
    }
}
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}