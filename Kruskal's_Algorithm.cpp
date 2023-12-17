#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define ff        first
#define ss        second
#define sz(x)    (int) x.size()
#define endl      '\n'
#define pb        push_back
#define all(v)    v.begin(), v.end()
#define     YES   printf("YES\n")
#define     Yes   printf("Yes\n")
#define     NO    printf("NO\n")
#define     No    printf("No\n")

#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)

const int lim = 1048576;
const int M    = 1e9 + 7;
const int Inf           = (int)2e9 + 5;
const ll  Lnf           = (ll)2e18 + 5;
const int N             = 5e5 + 5;
const int NN            = 1e6 + 5;

#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s, char c) {vector<string>v; stringstream ss(s); string x; while (getline(ss, x, c))v.emplace_back(x); return move(v);} void err(vector<string>::iterator it) {}
template<typename T, typename... Args>void err(vector<string>::iterator it, T a, Args...args) {cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " "; err(++it, args...);}

int par[N],sz[N];

void make(int u)
{
	par[u]=u;
	sz[u]=1;
	return;
}

int find(int u)
{
	if(par[u]==u)return u;
	return par[u]=find(par[u]);
}

void Union(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a!=b)
	{
		if(sz[a]<sz[b])swap(a,b);
		par[b]=a;
		sz[a]+=sz[b];
	}
	return;
}

int solve()
{
  int n,m;
  cin>>n>>m;
  std::vector<pair<int,pair<int,int>>>edges;
  for (int i = 0; i <m; ++i)
  {
    int u,v,wt;
    cin>>u>>v>>wt;
    edges.push_back({wt,{u,v}});
  }
  for (int i = 0; i <=n; ++i)
  {
  	make(i);
  }
  sort(edges.begin(), edges.end());
   int total_cost=0;
   for (auto edge:edges)
   {
   	int wt=edge.first;
   	int u=edge.second.first;
   	int v=edge.second.second;
   	if(find(u)==find(v))continue;
   	total_cost+=wt;
   	Union(u,v);
   	cout<<u<<" "<<v<<endl;


   }

   cout<<total_cost<<endl;
 
  return 0;
  //error();
}
int main() {
  
  //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 int test = 1, tc = 0;
  //cin >> test;
  while (test--) {
    //printf("Case %d: ", ++tc);
    solve();
  } 

  return 0;
}

