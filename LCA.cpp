/*
 * Author: Quan Pham
 * Tree with n edges, n <= 1e5, node start at 1
 * Find LCA
 * Enter number of edges and queries, the edge that joins 2 node
 * Output: LCA
 */

#include    <bits/stdc++.h>
#define     ll long long
#define     ull unsigned long long
#define     ld long double
#define     prec(k) fixed << setprecision(k)
#define     up(i, k, n) for (int i = k ; i < n ; i ++)
#define     down(i, k, n) for (int i = k ; i >= n ; i --)
#define     QuanPham
const int maxN = (int) 1e4 + 7;
const int maxM = (int) 1e5 + 7;
const int maxT = (int) 1e6 + 7;

using namespace std;

int n, q, h[maxM], p[maxM][20], t[maxM]; vector <int> adj[maxM];

void enter()
{
	cin >> n >> q;
	int u, v;
	up(i, 1, n)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void DFS(int u)
{
	for (auto v : adj[u])
	if (h[v] == -1) t[v] = u, h[v] = h[u] + 1, DFS(v);
}

void Prepare()
{
	memset(h, -1, sizeof(h));
	memset(p, -1, sizeof(p));
	h[1] = 0;
	DFS(1);

	up(i, 1, n + 1) p[i][0] = t[i];

	for (int j = 1 ; (1 << j) <= n ; j ++)
	up(i, 1, n + 1)
	if (p[i][j - 1] != -1)
	p[i][j] = p[p[i][j - 1]][j - 1];
}

int LCA(int u, int v)
{
	if (h[u] < h[v]) swap(u, v);
	down(i, 19, 0)
	if (h[u] - (1 << i) >= h[v])
	u = p[u][i];

	if (u == v) return u;

	down(i, 19, 0)
	if (p[u][i] != p[v][i])
	u = p[u][i], v = p[v][i];

	return t[u];
}

void solve()
{
	int u, v;
	while (q --)
	{
		cin >> u >> v;
		cout << LCA(u, v) << '\n';
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
    Prepare();
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
