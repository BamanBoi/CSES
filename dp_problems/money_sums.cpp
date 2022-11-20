#include<bits/stdc++.h>
using namespace std;
// bool dp[100010][110];
// bool func(int arr[],int sum,int index){
//     if(sum==0){
//         return true;
//     }
//     if(index<0){
//         return false;
//     }
//     if(dp[sum][index]!=false){
//         return dp[sum][index];
//     }
//     if(sum<arr[index]){
//         return dp[sum][index]=func(arr,sum,index-1);
//     }
//     return dp[sum][index]=(func(arr,sum,index-1) || func(arr,sum-arr[index],index-1));
// }
// bool func(vector<long long>& arr,long long target,int n){
//     bool ans[n+1][target+1];
//     for (int i = 0; i <=n; i++)
//     {
//         ans[i][0]=1;
//     }
//      for (int i = 1; i <=target; i++)
//     {
//         ans[0][i]=0;
//     }
//     for (int i = 1; i <=n; i++)
//     {
//         for (int j = 1; j <=target; j++)
//         {
//             if(arr[i-1]>j){
//                 ans[i][j]=ans[i-1][j];
//             }
//             else{
//                 ans[i][j]=ans[i-1][j] || ans[i-1][j-arr[i-1]];
//             }
//         }
//     }
//     return ans[n][target];
// }
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<long long>arr(n);
    long long sum=0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    // long long min=arr[0];
    // for (int i = 0; i < n; i++)
    // {
    //     if(arr[i]<min){
    //         min=arr[i];
    //     }
    // }
    int count=0;
    //cout<<sum<<endl;
    vector<int>v;
    bool ans[n+1][sum+1];
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=sum; j++)
        {
            ans[i][j]=false;
        }
        
    }
    ans[0][0]=true;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 0; j <=sum; j++)
        {
            ans[i][j]=ans[i-1][j];
            //int prev=j-arr[i-1];
            if(j-arr[i-1]>=0 && ans[i-1][j-arr[i-1]]){
                ans[i][j]=true;
            }
        }
    }
    //cout<<func(arr,sum,n);
    // for (long long i = min; i <=sum; i++)
    // {
    //     if(func(arr,i,n)){
    //         count++;
    //         v.push_back(i);
    //     }
    // }
    for (int i = 1; i <=sum; i++)
    {
        if(ans[n][i]){
            count++;
            v.push_back(i);
        }
    }
    cout<<count<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}