#include<bits/stdc++.h>
using namespace std;
const int N=10000;
vector<int> g[N];
bool vis[N]={false};
bool arr[N]={false};
int x=0;
int rest=0;
void dfs(int vertex,int ct,int m){
    if(vis[vertex]){
        return;
    }
    vis[vertex]=true;
    if(arr[vertex]){
        ct++;
        //cout<<"Cat-"<<ct<<endl;
    }
    else{
        ct=0;
    }
    if (ct>m)
    {
    //cout<<"Cat-"<<ct<<endl;
        return;
    }
    
    if(g[vertex].size()==1 && vertex!=1){
       // cout<<vertex<<endl;
        rest++;
        return;
    }
    //cout<<ct<<endl;
    for(auto child:g[vertex] ){
        //cout<<ct<<endl;
        dfs(child,ct,m);
        //rest++;
    }
}
int main(){
    int n,m;
    
    cin>>n>>m;
    
    for (int i = 1; i <=n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i <n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0,m);
    cout<<rest<<endl;
    return 0;
}