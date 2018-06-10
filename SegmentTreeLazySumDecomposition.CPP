/*
 * Update a number
 * Query a segment
 * Decompose tree
 */
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

struct NodeData
{
    int lef, rig;
    ll lazy, val;
    NodeData()
    {
        lazy = val = 0;
    }

    NodeData(int lef, int rig, ll val)
    {
        this->lef = lef;
        this->rig = rig;
        this->val = val;
    }
};

NodeData tree[maxT];
static int m, n, a[maxT], L[maxT], R[maxT], leaf[maxT], id[maxT], z[maxT];
vector <int> adj[maxM], tt;

void BuildTree(int x, int l, int r)
{
	if (l > r) return;
	tree[x] = NodeData(l, r, 0);
	if (l == r)
	{
		tree[x] = NodeData(l, r, a[l]);
		leaf[l] = x;
		return;
	}

	int mid = l + r >> 1;
	BuildTree(x * 2, l, mid);
	BuildTree(x * 2 + 1, mid + 1, r);
	tree[x].val = tree[x * 2 + 1].val + tree[x * 2].val;
}

ll Query(int x, int l, int r)
{
	if (l > tree[x].rig || r < tree[x].lef) return 0;
	if (l <= tree[x].lef && tree[x].rig <= r) return tree[x].val;
	return Query(x * 2, l, r) + Query(x * 2 + 1, l, r);
}

void Update(int id, int k)
{
	int x = leaf[id];
	a[id] = k;
	tree[x].val = k;
	for (x /= 2 ; x > 0 ; x /= 2)
	tree[x].val = tree[x * 2].val + tree[x * 2 + 1].val;
}

int Time = 0; static bool avail[maxM];

void Visit(int u)
{
	tt.push_back(u);
	avail[u] = true;
    L[u] = ++Time;
    for (int v: adj[u])
    if (!avail[v]) Visit(v);
    R[u] = Time;
}

void enter()
{
	int u, v;
	cin >> n >> m;
	up(i, 1, n + 1) cin >> z[i];
	up(i, 1, n)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	Visit(1);
	up(i, 1, n + 1)
	id[tt[i - 1]] = i;
	up(i, 1, n + 1)
	a[id[i]] = z[i];

	BuildTree(1, 1, n);
}

int main()
{
    #ifdef QuanPham
    auto start = chrono::steady_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen ("SCOMP.INP", "r", stdin);
    freopen ("SCOMP.OUT", "w", stdout);

    enter();
    char type; int x, k;
    while (m --)
    {
    	cin >> type >> x;
    	switch(type)
    	{
    		case 'Q': cout << Query(1, L[x], R[x]) << '\n'; break;
    		case 'U': cin >> k, Update(id[x], k); break;
    	}
    }

    #ifdef QuanPham
    auto end = chrono::steady_clock::now();
    cerr << "In milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << '\n' << "In seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count() << '\n';
    #endif
    return 0;
}
