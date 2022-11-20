#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int main(){
    int n;
    cin>>n;
    char arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    int dp[n+1][n+1];
    if(arr[0][0]=='*'){
       cout<<0<<endl;
       return 0;
    }
    else{
        dp[0][0]=1;
        for (int i = 1; i <n; i++)
        {
            if(arr[i][0]=='*'){
                dp[i][0]=0;
            }
            else{
                dp[i][0]=dp[i-1][0];
            }
        }
        for (int j = 1; j <n; j++)
        {
            if(arr[0][j]=='*'){
                dp[0][j]=0;
            }
            else{
                dp[0][j]=dp[0][j-1];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if(arr[i][j]=='*'){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j]=(dp[i-1][j]%M+dp[i][j-1]%M)%M;
            }
        }
        
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}