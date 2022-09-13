#include <bits/stdc++.h>
using namespace std;
#define inf 1e17;
const int N = 1e5;
long long arr[N][3];
vector<long long> dist(N);
vector<int> ans;
vector<long long> par(N,-1);
int main()
{
    for (int i = 0; i < N; i++)
    {
        dist[i] = inf;
    }
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <=m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        arr[i][0] = a;
        arr[i][1] = b;
        arr[i][2] = c;
    }
    int x;
    bool flag = true;
    for (int cnt = 1; cnt < n; cnt++)
    {
        x=-1;
        for (int i = 1; i <= m; i++)
        {

            int source = arr[i][0];
            int destination = arr[i][1];
            int wt = arr[i][2];
            if (dist[source] + wt < dist[destination])
            {
                dist[destination] = dist[source] + wt;
                par[destination]=source;
                x=destination;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int source = arr[i][0];
        int destination = arr[i][1];
        int wt = arr[i][2];
        if (dist[source] + wt < dist[destination])
        {
            flag = 0;
            //ans.push_back(source);
            //break;
        }
    }
    //int x=-1;
    if (flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            x=par[x];
        }
        for (int v = x;;v=par[v])
        {
            ans.push_back(v);
            if(x==v && ans.size()>1){
                break;
            }
        }
        reverse(ans.begin(),ans.end());
        for(auto it : ans){
            cout<<it<<" ";
        }
    }
    
    return 0;
}