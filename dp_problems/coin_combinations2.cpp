#include<bits/stdc++.h>
using namespace std;
int dp[110][1000010];
long long M=1e9+7;
long long func(int index,int target,vector<int>& arr){
    if(target==0){
        return 1;
    }
    if(index<0){
        return 0;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    long long ans=0;
    for (int i = 0; i<=target; i+=arr[index])
    {
        ans=(ans+func(index-1,target-i,arr))%M;
    }
    return dp[index][target]=(ans%M);
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<func(n-1,x,arr);
    return 0;
}