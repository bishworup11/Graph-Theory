#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int par[N];

int findroot(int u)
{
   if(par[u]==u)
    return u;
  else
    return par[u]=findroot(par[u]);
}

void merge_set(int u ,int v)
{
  u=findroot(u);
  v=findroot(v);

  if(u!=v)
    par[u]=v;
}

int main()
{
    int n,Test,i,j,b,m,x,y,z,sum=0,p;
    
      cin>>n>>m;
      int u,v;
      for(i=1;i<=m;i++)
      {
      	par[i]=i;
      }
      
       for(i=1;i<=n;i++)
      {
        cin>>u>>v;
      if(u>v)
      {
        m=u;
        u=v;
        v=m;
      }

      merge_set(u,v);
      }
      

      cin>>b;
      cout<<findroot(b);



    return 0;

}