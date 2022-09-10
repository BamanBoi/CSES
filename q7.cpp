#include<bits/stdc++.h>
using namespace std;
//int ans=0;
const int N=1e5;
int dp[N][3];
int func(int arr[][3],int index,int r,int n){
    if (r==n)
    {
        return 0;
    }
    if(dp[r][index+1]!=-1){
        return dp[r][index+1];
    }
    int sum=0;
    for (int i = 0; i < 3; i++)
    {
        if(i!=index){
        sum=max(sum,func(arr,i,r+1,n)+arr[r][i]);
        }
    }
    return dp[r][index+1]=sum;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int arr[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    int ans=func(arr,-1,0,n);
    cout<<ans<<endl;
    return 0;
}