#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int func(int a,int b){
    if(a==b){
        return 0;
    }
    if(dp[a][b]!=-1){
        return dp[a][b];
    }
    //int c=max(a,b);
    //int d=min(a,b);
    int ans=INT_MAX;
    for(int i=1;i<a;i++){
       ans=min(ans,1+func(a-i,b)+func(i,b));
    }
    for(int i=1;i<b;i++){
       ans=min(ans,1+func(a,b-i)+func(a,i));
    }
    return dp[a][b]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int a,b;
    cin>>a>>b;
    cout<<func(a,b);
    return 0;
}