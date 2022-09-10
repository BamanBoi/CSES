#include<bits/stdc++.h>
using namespace std;
const int N=100000;
vector<pair<int,int>> g[10000];
void solve(int n,int k){
    vector<vector<int>> dist;
    dist.resize(n+1);
    for (int i = 1; i <=n; i++)
    {
        dist[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            dist[i][j]=INFINITY;
        }
        
    }
    
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    solve(n,k);
    return 0;
}