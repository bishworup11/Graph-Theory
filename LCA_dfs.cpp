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
int par[N];
void dfs(int vertex, int p = -1)
{
	par[vertex] = p;
	for (int child : g[vertex])
	{
		if (p == child)continue;
		dfs(child, vertex);
	}
}
vector<int>path(int v)
{
	vector<int>ans;
	while (v != -1)
	{
		ans.push_back(v);
		v = par[v];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	cout << "Input queary" << endl;
	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		vector<int>path_x = path(x);
		vector<int>path_y = path(y);
		int mn_ln = min(path_x.size(), path_y.size());
		int lca = -1;

		for (int i = 0; i < mn_ln; ++i)
		{
			if (path_x[i] == path_y[i])
			{
				lca = path_x[i];
			}
			else
				break;
		}

		cout << lca << endl;

	}




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

