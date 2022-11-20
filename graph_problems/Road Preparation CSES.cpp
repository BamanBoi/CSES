#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long parent[N];
void make(int a){
    parent[a]=a;
}
long long find(int a){
    if(a==parent[a]){
        return a;
    }
    return parent[a]=find(parent[a]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        parent[a]=b;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<long long,pair<long long,long long>>> g;
    for (int i = 0; i < m; i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        g.push_back({c,{a,b}});
    }
    sort(g.begin(),g.end());
    for (int i = 1; i <=n; i++)
    {
        make(i);
    }
    long long ans=0;
    for(auto child:g){
        long long wt=child.first;
        long long ver1=child.second.first;
        long long ver2=child.second.second;
        if(find(ver1)==find(ver2)){
            continue;
        }
        Union(ver1,ver2);
        ans+=wt;
    }
    bool flag=true;
    int k=find(1);
    for (int i = 2; i <=n; i++)
    {
        if(find(i)!=k){
           flag=false;
        }
    }
    if(flag){
    cout<<ans<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
