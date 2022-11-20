#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int parent[N];
vector<int> g[N];
vector<bool> vis(N);
vector<int> ans;
void dfs(int src,int par){
    //bool loop=false;
    vis[src]=1;
    ans.push_back(src);
    for(auto child:g[src]){
        if(vis[child] && child==par){
            continue;
        }
        //ans.push_back(child);
        if(vis[child]){
            ans.push_back(child);
            auto index=find(ans.begin(),ans.end(),child);
            cout<<ans.end()-(index)<<endl;
            while(index!=ans.end()){
                cout<<*index<<" ";
                index++;
            }
            exit(0);
        }
        else{
            dfs(child,src);
        }
        //loop |=dfs(child,src,ans);
    }
    ans.pop_back();
    //return loop;
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i < n; i++)
    {
        if(!vis[i]){
            dfs(i,0);
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
   return 0;
}
