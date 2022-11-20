#include <bits/stdc++.h>
using namespace std;
int dp[5010][5010];
// int func(string s1,int i,string s2,int j){
//     if(i<0){
//         return j+1;
//     }
//     if(j<0){
//         return i+1;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     if(s1[i]==s2[j]){
//         return 0+func(s1,i-1,s2,j-1);
//     }
//     int a=func(s1,i,s2,j-1)+1;
//     a=min(a,func(s1,i-1,s2,j)+1);
//     a=min(a,func(s1,i-1,s2,j-1)+1);
//     return dp[i][j]=a;
// }
int main()
{
    // memset(dp,-1,sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }else{
            int a = dp[i][j - 1] + 1;
            a = min(a, dp[i - 1][j] + 1);
            a = min(a, dp[i - 1][j - 1] + 1);
             dp[i][j] = a;
            }
        }
    }
    cout<<dp[n][m]<<endl;
    // cout<<func(s1,n-1,s2,m-1);
    return 0;
}