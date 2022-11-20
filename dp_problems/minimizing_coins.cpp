#include<bits/stdc++.h>
using namespace std;
long long dp[1000010];
int arr[1000010];
long long func(int n,int x){
    if(x==0){
        return 0;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    long long ans=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(x>=arr[i]){
        ans=min(ans,func(n,x-arr[i])+1);
        }
    }
    return dp[x]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,x;
    cin>>n>>x;
    
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    long long ans=func(n,x);
    if(ans<INT_MAX){
        cout<<ans;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}