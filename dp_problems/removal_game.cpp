#include<bits/stdc++.h>
using namespace std;
long long dp[5000][5000][2];
long long func(int start,int end,vector<long long>& v,int turn){
    if(start>end){
        return 0;
    }
    if(dp[start][end][turn]!=-1){
        return dp[start][end][turn];
    }
    if(turn){
        return dp[start][end][turn]=max(v[start]+func(start+1,end,v,0),v[end]+func(start,end-1,v,0));
    }
    else{
        return dp[start][end][turn]=min(func(start+1,end,v,1),func(start,end-1,v,1));
    }
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<func(0,n-1,arr,1);
    return 0;
}