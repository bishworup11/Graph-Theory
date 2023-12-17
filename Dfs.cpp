#include<bits/stdc++.h>
#include<queue>
using namespace std;

vector<int> adj[202];
bool vis[102];
int edge_id[100];
void dfs(int s, int n)
{
	for (int i = 0; i < n; ++i)
	{
		edge_id[i]=vis[i]=0;
	}
	stack<int>S;
	S.push(s);
	vis[s]=1;
	while(!S.empty())
	{
		int u=S.top();

		S.pop();
		if(edge_id[u]==0)
		{
			cout<<u<<"\t ";
		}


		while(edge_id[u]<adj[u].size())
		{
			int v=adj[u][edge_id[u]];
			edge_id[u]++;
			if(vis[v]==0)
			{
				vis[v]=1;
				S.push(u);
				S.push(v);
				break;
			}

		}

	}

}



int main()
{
    int n,Test,i,j,b,m,x,y,z,sum=0,s;

      cin>>n>>m;
      for(i=1;i<=m;i++)
      {
      	int u,v;
      	cin>>u>>v;
      	adj[u].push_back(v);
      	adj[v].push_back(u);

      }
      cin>>s;
      dfs(s,n);

    return 0;

}
