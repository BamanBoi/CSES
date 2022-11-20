#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n, m, k;
vector<vector<pair<int,int>>> g;
vector<vector<int>> dist; 
const int INF = 9e15;
 
void dij()
{
 
	priority_queue <
	  pair<int,int>, 
	  vector<pair<int,int>>, 
	  greater<pair<int,int>>
	> pq; 
 
	pq.push({0,1});
 
	while(!pq.empty())
	{
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
 
		if(dist[u][k-1] < d) continue;
 
		for(auto e: g[u])
		{
			int v = e.first;
			int c = e.second;
 
			if(dist[v][k-1] > c+d) 
			{
				dist[v][k-1] = c+d;
				pq.push({dist[v][k-1], v});
				sort(dist[v].begin(), dist[v].end());
			}
		}
	}
}
 
int32_t main()
{
	cin >> n >> m >> k;
	g.resize(n+1);
	dist.resize(n+1);
	for(int i = 1; i <= n; i++)
	{
		dist[i].resize(k);
		for(int j = 0; j <k; ++j)
		{
			dist[i][j] = INF;
		}
	}
	dist[1][0] = 0;
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
 
	dij();
 
	for(int i = 0; i < k; ++i)
	{
		cout << dist[n][i] << " ";
	}
}
