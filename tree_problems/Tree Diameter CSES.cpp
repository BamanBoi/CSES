#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
vector<int>g[N];
int depth[N];
void dfs(int src,int par=-1){
    for(auto child:g[src]){
        if(child==par){
            continue;
        }
        depth[child]=depth[src]+1;
        dfs(child,src);

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
    int diameter=0;
    int max_depth_node;
    for (int i = 1; i <=n; i++)
    {
        if(diameter<depth[i]){
            diameter=depth[i];
            max_depth_node=i;
        }
        depth[i]=0;
    }
    dfs(max_depth_node);
    for (int i = 1; i <=n; i++)
    {
        if(diameter<depth[i]){
            diameter=depth[i];
        }
    }
    cout<<diameter<<endl;
    return 0;
}
