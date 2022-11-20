#include<bits/stdc++.h>
using namespace std;
int dp[1001][100010];
// int func(int index,int x,vector<int>& h,vector<int>& s){
//     if(x==0){
//         return 0;
//     }
//     if(index<0){
//         return 0;
//     }
//     if(dp[index][x]!=-1){
//         return dp[index][x];
//     }
//     int ans=0;
//     ans=func(index-1,x,h,s);
//     if(x>=h[index]){
//         ans=max(ans,func(index-1,x-h[index],h,s)+s[index]);
//     }
//     return dp[index][x]=ans;
// }
int main(){
    //memset(dp,-1,sizeof(dp));
    int n,x;
    cin>>n>>x;
    vector<int>h(n),s(n);
    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    for (int i = 0; i <n; i++)
    {
        dp[i][0]=0;
    }
    for (int i = 1; i <=x; i++)
    {
        dp[0][i]=0;
    }
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=x; j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=h[i-1]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-h[i-1]]+s[i-1]);
            }
        }
        
    }
    cout<<dp[n][x]<<endl;
    //cout<<func(n,x,h,s);
    return 0;
}