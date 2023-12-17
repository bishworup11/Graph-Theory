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
std::vector<int>g[N];
int subtree_sum[N];
int evencount[N];
void dfs(int vertex,int par)
{  

	subtree_sum[vertex]+=vertex;
	if(vertex%2==0)evencount[vertex]++;
	for (int i = 0; i <g[vertex].size(); ++i)
	{
	  int child=g[vertex][i];
	  if(child==par)continue;

	  dfs(child,vertex);
	  subtree_sum[vertex]+=subtree_sum[child];
	  evencount[vertex]+=evencount[child]; 
	}
}

int solve()
{
  int n,m;
  cin>>n>>m;
  for (int i = 0; i <m; ++i)
  {int v1,v2;
  	cin>>v1>>v2;
  	g[v1].push_back(v2);
  	g[v2].push_back(v1);      
  }
  dfs(1,0);
  int q;
  for (int i = 1; i <=n; ++i)
  {
  	error(i,subtree_sum[i],evencount[i]);
  }
  //cin>>q;
  // while(q--)
  // {
  //    int x;
  //    cin
  // }

 
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

