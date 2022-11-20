#include<bits/stdc++.h>
using namespace std;
long long M=1e9+7;
int arr[6]={1,2,3,4,5,6};
long long dp[1000010];
long long func(int target){
    if(target==0){
        return 1;
    }
    if(dp[target]!=-1){
        return dp[target];
    }
    long long ans=0;
    for(int i=0;i<=5;i++){
        if(target>=arr[i]){
       ans=(ans+func(target-arr[i]))%M;
        }
    }
    return dp[target]=ans%M;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<func(n);
    return 0;
}