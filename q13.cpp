#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int parent[N];
int sz[N];
void make(int v){
    parent[v]=v;
    sz[v]=1;
}
int find(int a){
    if(a==parent[a]){
        return a;
    }
    return find(parent[a]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sz[a]>sz[b]){
            parent[a]=b;
            sz[a]+=sz[b];
        }
        else{
            parent[b]=a;
            sz[b]+=sz[a];
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,pair<int,int>>> g;
    int x,y,wt;
    for (int i = 0; i < e; i++)
    {
        cin>>x>>y>>wt;
        g.push_back({wt,{x,y}});
    }
    sort(g.begin(),g.end());
    int ans=0;
    //vector<pair<int,int>> ans;
    for(auto it:g){
        int a=it.second.first;
        int b=it.second.second;
        int wght=it.first;
        if(find(a)==find(b)){
            continue;
        }
        Union(a,b);
        //ans.push_back({a,b});
        ans+=wght;
    }

    //cout<<v-1<<endl;
    // for(auto it: ans){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    cout<<ans<<endl;
    return 0;
}