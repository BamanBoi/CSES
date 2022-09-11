#include<bits/stdc++.h>
using namespace std;
#define inf 1e17;
vector<pair<int,int>> v[1000000],v2[1000000];
 
long long dis1[100005],dis2[100005];
void dijkstra(int source,long long d[],vector<pair<int,int>> k[]){
    bool vis[100005]={0};
    set<pair<long long,long long>> s;
    for (int i = 0; i < 100005; i++)
    {
        d[i]=inf;
    }
    s.insert({0,source});
    d[source]=0;
    //vector<int> max(100000,0);
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
        for(auto it : k[vertex]){
            int distance=it.second;
            int ver=it.first;
            if(d[vertex]+distance<d[ver]){  
                d[ver]=d[vertex]+distance;
                s.insert({d[ver],ver});
            }
        }
    }
    //cout<<d[3]<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    int a,b,c;
    vector<pair<int,pair<int,int>>> g;
    for (int i = 1; i <=m; i++)
    {
        cin>>a>>b>>c;
        g.push_back({a,{b,c}});
        v[a].push_back({b,c});
        v2[b].push_back({a,c});
    }
    dijkstra(1,dis1,v);
    dijkstra(n,dis2,v2);
    long long ans=inf;
    for(auto it: g){
        ans=min(ans,dis1[it.first]+dis2[it.second.first]+(it.second.second)/2);
    }
  cout<<ans<<endl;
    return 0;
}
