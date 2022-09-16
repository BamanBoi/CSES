#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
vector<int>g[N];
vector<bool> vis1(N);
vector<bool>vis3(N);
vector<bool>vis2(N);
stack<int> s;
bool dfs1(int src,int par){
     vis1[src]=1;
     vis3[src]=1;
    // bool ifloopexists=false;
    //ans.push_back(src);
    for(auto child:g[src]){
        if(!vis1[child]){
            if(dfs1(child,src)){
                return true;
            }
        }
        else if(vis3[child]){
           return true;
        }
    }
    vis3[src]=false;
    return false;
    //return ifloopexists;
}
void dfs(int source){
    vis2[source]=1;
    for(auto child:g[source]){
        if(!vis2[child]){
        dfs(child);
        }
    }
    s.push(source);
}
int main(){
    int n,m;
    cin>>n>>m;
    //bool flag=false;
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    // for (int i = 1; i <=n; i++)
    // {
    //     if(!vis1[i]){
    //        if(dfs1(i,0)){
    //         cout<<"Loop"<<endl;
    //         break;
    //        }
    //     }
    // }
    
    // if(!vis1[i] && dfs1(i,0)){
    //          cout<<"IMPOSSIBLE"<<endl;
    //          return 0;
    //      }
    for (int i = 1; i <=n; i++)
    {
        if(!vis1[i] && dfs1(i,0)){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        if(!vis2[i]){
            dfs(i);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}