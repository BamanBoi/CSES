#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[1000000];
void dijkstra(int source,int n){
    vector<bool> vis(n+1,0);
    vector<long long> dist(n+1,INFINITY);
    set<pair<long long,long long>> s;
    s.insert({1,source});
    dist[1]=0;
    while (s.size()>0)
    {
        auto min_node =*s.begin();
        int vertex=min_node.second;
        int wt=min_node.first;
        s.erase(s.begin());
        if(vis[vertex]){
            continue;
        }
        vis[vertex]=1;
        for(auto it : v[vertex]){
            int distance=it.second;
            int ver=it.first;
            if(dist[vertex]+distance<dist[ver]){
                dist[ver]=dist[vertex]+distance;
                s.insert({dist[ver],ver});
            }
        }
    }
    for (int i = 1; i <=n; i++)
    {
        cout<<dist[i]<<" ";
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    
    long long a,b,c;
    for (int i = 1; i <=m; i++)
    {
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        //v[b].push_back({a,c});
    }
    //vector<int> ans(n);
    dijkstra(1,n);
    
    
    return 0;
}