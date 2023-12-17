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

//tech dose//
std::vector<int>g[N], rev[N];
int n, m;
void dfs1(int node,vector<bool>&visited,stack<int>&mystack)
{
    visited[node]=true;
    for (int i = 0; i <g[node].size(); ++i)
    {
    	int v=g[node][i];
    	if(!visited[v])
    	{
    		dfs1(v,visited,mystack);
    	}
    }
    mystack.push(node);
    return ;
}

void dfs2(int node,vector<bool>&visited)
{
	visited[node]=true;
	cout<<node<<" ";
	for (int i = 0; i <rev[node].size(); ++i)
	{  int v=rev[node][i];
		if(!visited[v])
		{
			dfs2(v,visited);
		}
	}

	return;
}

void scc()
{
	stack<int>mystack;
	std::vector<bool>visited(n+5, false);
	for (int i = 1; i <= n; ++i)
	{  if(!visited[i])
		dfs1(i, visited, mystack);
	}
   
    for (int i = 0; i <=n; ++i)visited[i]=false;
    cout<<"connected components are \n";
    
    while(!mystack.empty())
    {
    	int v=mystack.top();
    	//error(v);
    	mystack.pop();
    	if(!visited[v])
    	{
    		dfs2(v,visited);
    		cout<<endl;
    	}
    }	

}

int solve()
{

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		rev[v].push_back(u);
	}

	scc();


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

