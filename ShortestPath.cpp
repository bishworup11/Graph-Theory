#include<bits/stdc++.h>
using namespace std;
#include<queue>
const int N = (int)1e5 + 5;
vector<int> adj[N];
int level[N];

bool visited [N];
int main()
{
	int n,m;
	

	memset(level , -1 , sizeof(level));
	  cout<<"Enter number of node and edge : "<<endl;
	cin>>n>>m;
	for (int i = 0; i <m; ++i)
	{
		cout<<"Enter "<<i+1<<"th edge node : ";
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int>q;
	q.push(1);
	visited[1]=1;
	level[1]=0;

	while(!q.empty())
	{
		int u=q.front();
		cout<<u<<" ";
		q.pop();
		for (int i = 0; i <adj[u].size(); i++)
		{
			 int v=adj[u][i];
			 if(level[v]==-1)
			 {
			 	level[v]=level[u]+1;
			 }
			if(visited[v]==0)
			{
				
				q.push(v);
				visited[v]=1;
			}

		}


	}

	for(int i=1;i<=n;i++){
     cout<<"1 node from "<<i<<" node of shortest path :"<<level[i]<<endl;
   }


	cout<<endl;
	return 0;
}