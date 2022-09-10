#include<bits/stdc++.h>
using namespace std;
long long w[110],v[110];
long long dp[110][100005];
long long func(int index,int wt){
    
    if(wt==0){
        return 0;
    }
    if(index<0){
        return 0;
    }
    if(dp[index][wt]!=-1){
        return dp[index][wt];
    }
    long long ans=func(index-1,wt);
if(wt-w[index]>=0){
    ans=max(ans,func(index-1,wt-w[index])+v[index]);
}
return dp[index][wt]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int N,W;
    cin>>N>>W;

    for (int i = 0; i < N; i++)
    {
        cin>>w[i]>>v[i];
       
    }
    long long ans=func(N-1,W);
    cout<<ans<<endl;
    return 0;
}