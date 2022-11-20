#include<bits/stdc++.h>
using namespace std;
const int INF =1e9;
int main(){
    int n;
    cin>>n;
    vector<int>v(n+1),lis(n+1,INF);
    for (int i = 0; i <n; i++)
    {
        cin>>v[i];
    }
    lis[0]=-INF;
   for (int i = 0; i < n; i++) {
        int j = upper_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        if (lis[j-1] < v[i] && v[i] < lis[j])
            lis[j] = v[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (lis[i] < INF)
            ans = i;
    }
    cout<<ans<<endl;
    return 0;
}