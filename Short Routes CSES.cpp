#include<bits/stdc++.h>
using namespace std;
#define inf 1e17;
const int N=1000;
long long dist[N][N];
int main(){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i==j){
                dist[i][j]=0;
            }
            else{
            dist[i][j]=inf;
            }
        }
        
    }
    int n,m,q;
    cin>>n>>m>>q;
    for (int i = 0; i < m; i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[b][a],c);
    }
    for (int k = 1; k <=n; k++)
    {
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <=n; j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
            
        }
        
    }
    for (int i = 0; i < q; i++)
    {
        int a,b;
        cin>>a>>b;
        if(dist[a][b]!=1e17){
        cout<<dist[a][b]<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    
    return 0;
}
