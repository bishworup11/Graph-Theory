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


#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s, char c) {vector<string>v; stringstream ss(s); string x; while (getline(ss, x, c))v.emplace_back(x); return move(v);} void err(vector<string>::iterator it) {}
template<typename T, typename... Args>void err(vector<string>::iterator it, T a, Args...args) {cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " "; err(++it, args...);}

const int lim = 1048576;
const int M    = 1e9 + 7;
const int Inf           = (int)2e9 + 5;
const ll  Lnf           = (ll)2e18 + 5;
const int N             = 5e5 + 5;
const int NN            = 1e6 + 5;

int dist[500+5][500+5];
int solve()
{
	for (int i = 0; i <505; ++i)
	{
	  for (int j = 0; j <505; ++j)
	  {
	  	if(i==j)dist[i][j]=0;
	  	else dist[i][j]=Inf;
	  }
	}
  int n,m;
  cin>>n>>m;
  for (int i = 0; i <m; ++i)
  {
  	int x,y,wt;
  	cin>>x>>y>>wt;
  	dist[x][y]=wt;
  }

  for (int k =1; k <=n; ++k)
  {
  	for (int i = 1; i <=n; ++i)
  	{
  		for (int j =1; j <=n; ++j)
  		{
  			dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
  		}
  	}
  }
 for (int i = 1; i <=n; ++i)
  	{
  		for (int j =1; j <=n; ++j)
  		{
  			cout<<dist[i][j]<<" ";
  		}

  		cout<<endl;
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

