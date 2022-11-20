#include<bits/stdc++.h>
using namespace std;
int dp[1000010];
int func(int n){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=INT_MAX;
    vector<int>arr;
    int temp=n;
    while (temp!=0)
    {
        arr.push_back(temp%10);
        //cout<<temp%10<<endl;
        temp=temp/10;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if(n>=arr[i] && arr[i]!=0){
        ans=min(ans,func(n-arr[i])+1);
        }
    }
    return dp[n]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<func(n);
    return 0;
}