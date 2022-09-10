#include<bits/stdc++.h>
using namespace std;
const int N=200000+200;
vector<int> g[N];
vector<int> lvl(N,1000000);
//vector<int> lis[N];
vector<bool> vis(N);
vector<int> ans(N);
void bfs(int source,int destination){
    queue<int> q;
    stack<int> s;
    lvl[1]=1;
    q.push(source);
    vis[source]=1;
    ans[1]=-1;
    while(!q.empty()){
      int a=q.front();
      q.pop();
      for(auto it:g[a]){
        if(!vis[it]){
        q.push(it);
        lvl[it]=lvl[a]+1;
        vis[it]=1;
        ans[it]=a;
        }
      }
    }
    
    if(lvl[destination]<1000000){
    cout<<lvl[destination]<<endl;
    int it=destination;
      while(it!=-1){
         s.push(it);
         it=ans[it];
      }
      while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
      }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    int a,b;
    for (int i = 0; i <e; i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(1,v);
    return 0;
}