#include<bits/stdc++.h>
using namespace std;
const int N=200000+100;
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
    return parent[a]=find(parent[a]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
       parent[b]=a;
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    for (int i = 1;i <=v; i++)
    {
        make(i);
    }
    int x,y;
    vector<pair<int,int>> g;
    for (int i = 0; i < e; i++)
    {
        cin>>x>>y;
        g.push_back({x,y});
        Union(x,y);
    }
    // for (int i = 1; i <=v; i++)
    // {
    //     cout<<find(i)<<endl;
    // }
    vector<pair<int,int>> ans;
    for (int i =2; i <=v; i++)
    {
        if(find(i)==find(1)){
            continue;
        }
        else{
        Union(find(1),i);
        ans.push_back({find(1),i});
        }
    }
    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
