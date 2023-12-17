#include<bits/stdc++.h>
#include<queue>
using namespace std;

vector<int> adj[202];
bool trav[102];


int main()
{
    int n,Test,i,j,b,m,x,y,z,sum=0,p;
    
      cin>>n>>m;
      for(i=1;i<=m;i++)
      {
      	int u,v;
      	cin>>u>>v;
      	adj[u].push_back(v);
      	adj[v].push_back(u);

      }


     queue< int > q;
     q.push(1);
     trav[1]=1;

     while( !q.empty() ) 
     {
        int u =q.front();

        cout<<u<<"\t";
        q.pop();

        for (int i = 0; i <adj[u].size(); i++)
        {
           if (trav[adj[u][i]]==0)
           	{
           		int v=adj[u][i];
           		trav[v]=1;
           		q.push(v);

           	}	
        }
        
    }




    return 0;

}