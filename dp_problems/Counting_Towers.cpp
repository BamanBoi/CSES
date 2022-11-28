#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        long long dp[n+1][2];
        dp[1][0]=1;
        dp[1][1]=1;
        for (int i = 2; i <=n; i++)
        {
            dp[i][0]=(4*dp[i-1][0]+dp[i-1][1])%M;
            dp[i][1]=(2*dp[i-1][1]+dp[i-1][0])%M;
        }
        cout<<(dp[n][0]+dp[n][1])%M<<endl;
    }
    
    return 0;
}
