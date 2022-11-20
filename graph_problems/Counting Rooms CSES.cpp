#include<bits/stdc++.h>
using namespace std;
bool vis[1001][1001];
int n,m;
char input[1001][1001];
int adjx[4]={0,1,0,-1};
int adjy[4]={1,0,-1,0};
bool isvalid(int x,int y){
    if(x<0 || y<0 || x>=n || y>=m || input[x][y]=='#'){
        return false;
    }
    return true;
}
void dfs(int x,int y){
    vis[x][y]=1;
    for (int i = 0; i < 4; i++)
    {
        int x2=x+adjx[i];
        int y2=y+adjy[i];
        if(isvalid(x2,y2)){
            if(!vis[x2][y2]){
                dfs(x2,y2);
            }
        }
    }
    
}
int main(){
    int ans=0;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>input[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && input[i][j]=='.'){
                dfs(i,j);
                ans++;
            }
        }
        
    }
    cout<<ans<<endl;
    return 0;
}
