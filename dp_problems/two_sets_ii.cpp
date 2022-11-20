// #include<bits/stdc++.h>
// using namespace std;
// long long dp[510][100000];
// const int M=1e9+7;
// long long func(int index,long long sum){
//     if(sum==0 ){
//         return 1;
//     }
//     if(index<=0){
//         return 0;
//     }
//     if(dp[index][sum]!=-1){
//         return dp[index][sum];
//     }
//     long long ans=0;
//     ans=(ans+func(index-1,sum))%M;
//     if(sum>=index){
//         ans=(ans+func(index-1,sum-index))%M;
//     }
//     return dp[index][sum]=(ans%M);
// }
// int main(){
//     memset(dp,-1,sizeof(dp));
//     int n;
//     cin>>n;
//     long long sum=(n*(n+1))/2;
//     if(sum%2!=0){
//         cout<<0<<endl;
//     }
//     // int arr[n];
//     // for (int i = 0; i < n; i++)
//     // {
//     //     arr[i]=i+1;
//     // }
//     else{
//     cout<<func(n,sum/2)/2;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    // read the input
    int n;
    cin >> n;
    int total = (n * (1 + n)) / 2; // sum of consecutive numbers e.g. 1,2,3...
    // check for edge case: total can't be divided into two sets
    if (total % 2 == 1) {
        cout << 0;
        return 0;
    }
    ll MOD = 1e9 + 7;
 
    // build the dp table
    int half = total / 2;
    vector<ll> dp(half + 1);
    dp[0] = 1;
    for (int coin = 1; coin <= n; coin++) {
        for (int i = half; i >= coin; i--) {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }
 
    ll modInverseOfTwo = 500000004;
    cout << (dp[half] * modInverseOfTwo) % MOD;
 
    return 0;
}