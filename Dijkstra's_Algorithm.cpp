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

std::vector<pair<int, int>>g[N];
std::vector<int>vis(N, 0);
std::vector<int>dist(N, Inf);
int n, m;
void dijkstra(int source)
{
	set<pair<int, int>>st;
	st.insert({0, source});
	dist[source]=0;

	while (st.size())
	{
		auto node = *st.begin();
		int v = node.ss;
		int dist_v = node.ff;
		st.erase(st.begin());
		//error(v,dist_v);
		if (vis[v])continue;
		vis[v] = 1;
		for (auto child : g[v])
		{
			int child_v=child.ff;
			int wt=child.ss;
			if(dist[v]+wt<dist[child_v])
			{
				dist[child_v]=dist[v]+wt;
				st.insert({dist[child_v],child_v});
			}
		}
	}

	for (int i =1; i <=n; ++i)
	{
		cout<<"Node :"<<i<<" distance "<<dist[i]<<endl;
	}

}

// void dijkstra(int source)
// {
// 	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

// 	pq.push({0, source});
// 	while (!pq.empty())
// 	{
// 		pair<int, int>p = pq.top();
// 		pq.pop();
// 		int v = p.ss;
// 		int dist_v = p.ff;
// 		if (vis[v])continue;
// 		dist[v] = dist_v;
// 		vis[v] = 1;
// 		for (auto child : g[v])
// 		{
// 			int child_v = child.ff;
// 			int wt = child.ss;
// 			if (vis[child_v])continue;
// 			pq.push({dist[v] + wt, child_v});
// 		}
// 	}


// 	for (int i = 1; i <= n; ++i)
// 	{
// 		cout << "node " << i << " distance :" << dist[i] << endl;
// 	}

// }


int solve()
{
	//int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y, wt;
		cin >> x >> y >> wt;
		g[x].push_back({y, wt});
		g[y].push_back({x, wt});
	}
   clock_t tStart = clock();
	dijkstra(1);

   printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	return 0;
	//error();
}
int main() {

	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int test = 1, tc = 0;
	//cin >> test;
	//scanf("%d", &test);
	while (test--) {
		//printf("Case %d: ", ++tc);
		solve();
	}
	
	return 0;
}

