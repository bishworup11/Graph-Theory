#include<bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
std::vector<int>g[N];
std::vector<pair<int , int >> vt;
int vis[N], low[N], in[N];
int time1 = 0;
void dfs(int node, int p)
{
	vis[node] = 1;
	in[node] = low[node] = time1;
	time1++;
	for (int i = 0; i < g[node].size(); ++i)
	{
		int u = g[node][i];
		if (u == p) continue;

		if (vis[u] == 1)
		{
			low[node] = min(low[node], in[u]);
		}

		else
		{
			dfs(u, node);
			if (in[node] < low[u])
			{
				vt.push_back({node, u});
			}

			low[node] = min(low[node], low[u]);

		}

	}

}

int main()
{

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);

	}

	for (int i = 1; i <= n; ++i)
	{
		dfs(i, -1);
	}

	cout << "number of bridge " <<

	     for (int i = 0; i < vt.size(); ++i)
	{
		cout << vt[i].first << " " << vt[i].second << " " << endl;
	}

	return 0;
}