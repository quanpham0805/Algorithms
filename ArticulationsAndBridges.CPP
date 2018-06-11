#include    <bits/stdc++.h>
#define     ll long long
#define     ull unsigned long long
#define     ld long double
#define     prec(k) fixed << setprecision(k)
#define     up(i, k, n) for (int i = k ; i < n ; i ++)
#define     down(i, k, n) for (int i = k ; i >= n ; i --)
#define     ii pair<int, int>
#define     pll pair <ll, ll>
#define     X first
#define     Y second
#define     str basic_string <int>
#define     QuanPham
const int maxN = (int) 1e4 + 7;
const int maxM = (int) 1e5 + 7;
const int maxT = (int) 1e6 + 7;

using namespace std;

static int n, m, low[maxM], num[maxM], parent[maxM], cnt, childnum[maxM];
vector <int> adj[maxM];
static bool IsArticulation[maxM];

void DFS(int u)
{
	num[u] = ++ cnt;
	low[u] = maxT;
	for (auto v : adj[u])
	if (parent[v] == 0)
	{
		parent[v] = u;
		DFS(v);
		low[u] = min(low[u], low[v]);
	}
	else if (parent[v] != 0 && v != parent[u]) low[u] = min(low[u], num[v]);

}

void Bridges()
{
	cout << "Briges :" << '\n';
	up(v, 1, n + 1)
	{
		int u = parent[v];
		if (u != -1 && low[v] >= num[v])
			cout << u << ' ' << v << '\n';
	}
}

void Articulations()
{
	cout << "Articulations : " << '\n';
	up(v, 1, n + 1)
	{
		int u = parent[v];
		if (u != -1) childnum[u] ++;
	}

	up(u, 1, n + 1)
	IsArticulation[u] = (childnum[u] >= 2 && parent[u] == -1);

	up(v, 1, n + 1)
	{
		int u = parent[v];
		if (u != -1 && parent[u] != -1 && low[v] >= num[u])
			IsArticulation[u] = true;
	}

	up(i, 1, n + 1)
	if (IsArticulation[i]) cout << i - 1 << '\n';
}

void ArticulationAndBridge()
{
	Bridges();
	Articulations();
}

void solve()
{
	up(u, 1, n + 1)
	if (parent[u] == 0) parent[u] = -1, DFS(u);

	ArticulationAndBridge();
}

void enter()
{
	cin >> n >> m;
	int u, v;
	up(i, 0, m)
	{
		cin >> u >> v;
		u ++, v ++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int main()
{
    #ifdef QuanPham
    auto start = chrono::steady_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    enter();
    solve();

    #ifdef QuanPham
    auto end = chrono::steady_clock::now();
    cerr << "In milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << '\n' << "In seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count() << '\n';
    #endif
    return 0;
}
