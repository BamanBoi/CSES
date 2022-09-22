#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
const int N=1e6;
vector<int>g[N];
vector<bool>vis(N);

vector<int> s;
void dfs(int src){
    vis[src]=1;
    for(auto child:g[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
    s.push_back(src);
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[b].push_back(a);
    }
    for (int i = 1; i <=n; i++)
    {
        if(!vis[i]){
        dfs(i);
        }
    }
    int wt[100005]={0};
    vector<int>s2;
    int i=0;
    while(i<s.size())
    {
        s2.push_back(s[i]);
        i++;
    }
    wt[1]=1;
    for(auto i:s2){
        for(auto j:g[i]){
            (wt[i]+=wt[j])%=MOD;
        }
    }
    //dfs(1,n);
    cout<<wt[n]<<endl;
    return 0;
}
