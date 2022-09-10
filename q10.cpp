#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
vector<pair<int,int>> g[100000];
int solve(int x,int y){
    vector<long long> distance(N,1000000000000);
    vector<bool> vis(N,0);
    set<pair<long long,long long>> st;
    st.insert({0,x});
    distance[x]=0;
    while (st.size()>0)
    {
        auto min_node=*st.begin();
        int vertex=min_node.second;
        int wt=min_node.first;
        st.erase(st.begin());
        if(vis[vertex]){
            continue;
        }
        vis[vertex]=1;
        for(auto child:g[vertex]){
            int dista=child.second;
            int ver=child.first;
            if(distance[vertex]+dista<distance[ver]){
                distance[ver]=distance[vertex]+dista;
                st.insert({distance[ver],ver});
            }
        }
    }
    if(distance[y]<1000000000000){
        return distance[y];
    }
    return -1;
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    long long a,b,c;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    int x,y;
    while (q--)
    {
        cin>>x>>y;
        int ans=solve(x,y);
        cout<<ans<<endl;
    }
    
    return 0;
}