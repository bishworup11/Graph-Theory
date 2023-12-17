#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;
#define Yes printf("Yes\n")
#define No printf("No\n")
#define YES printf("YES\n")
#define NO printf("NO\n")
#define Noo printf("-1\n")
#define pt(x) cout << x << endl;
#define ptt(x, y) cout << x << " " << y << endl;
#define fr(n) for (int i = 0; i < n; i++)
#define fr1(n) for (int i = 1; i <= n; i++)
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define mod 1000000007
#define mem(a) memset(a, 0, sizeof a)
#define memn(a) memset(a, -1, sizeof a)

template <typename T> inline void Int(T &n)
{
    n = 0;
    int f = 1;
    register int ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = -1;
    for (; isdigit(ch); ch = getchar())
        n = (n << 3) + (n << 1) + ch - '0';
    n = n * f;
}

template <typename T, typename TT> inline void Int(T &n, TT &m)
{
    Int(n);
    Int(m);
}
template <typename T, typename TT, typename TTT> inline void Int(T &n, TT &m, TTT &l)
{
    Int(n, m);
    Int(l);
}

#define error(args...)                                                                                                 \
    {                                                                                                                  \
        vector<string> _v = split(#args, ',');                                                                         \
        err(_v.begin(), args);                                                                                         \
        cout << endl;                                                                                                  \
    }
vector<string> split(const string &s, char c)
{
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c))
        v.emplace_back(x);
    return move(v);
}
void err(vector<string>::iterator it)
{
}
template <typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args)
{
    cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " ";
    err(++it, args...);
}

long long Inv_pow(long long a, long long n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = ((res % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        n >>= 1;
    }
    return res % mod;
}

const int lim = 1048576;
const int Inf = (int)2e9 + 5;
const ll Lnf = (ll)2e18 + 5;
const int N = 2e5 + 5;
const int NN = 1e7 + 2;
const ll M = 1e9 + 7;

std::vector<int> g[N];

int par[N], last = 0, sum = 0;

void dfs(int p, int node, int s)
{
    par[node] = p;
    if (s >= sum)
    {
        last = node;
        sum = s;
    }

    error(p, node);
    for (auto child : g[node])
    {
        if (p == child)continue;
        dfs(node, child, s + 1);
    }

    return ;
}

int solve()
{
    ll n, m, k, sum = 0, ct = 0, ans = -1;

    cout << "input vertex and edge\n";
    Int(n, m);

    for (int i = 0; i <= n + 5; ++i)
    {
        g[i].clear();
        par[i] = 0;
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        Int(u, v);
        g[u].pb(v);
        g[v].pb(u);

    }

    dfs(-1, 1, 0);

    for (int i = 0; i <= n + 5; ++i)
    {
        par[i] = 0;
    }


    cout << last << endl;

    dfs(-1, last, 0);

    std::vector<int> v;
    cout << last << endl;


    while (last != -1)
    {   cout << last << " ";
        v.pb(last);
        last = par[last];

    }

    cout << endl;






    return 0;
}

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int test = 1, tc = 0;
    //Int(test);
    // cin >> test;
    while (test--)
    {
        // printf("Case %d: ", ++tc);
        solve();
    }
    return 0;
}
