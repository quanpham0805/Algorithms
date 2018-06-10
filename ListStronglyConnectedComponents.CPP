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

int n, m, u, v; vector <int> adjf[maxM], adjb[maxM];
bool avail[maxM]; stack <int> s;

void DFS(int u)
{
	avail[u] = false;
	for (auto v : adjf[u])
	if (avail[v]) DFS(v);
	s.push(u);
}

void PrintRes(int u)
{
	cout << u << ' ';
	avail[u] = false;
	for (auto v : adjb[u])
	if (avail[v]) PrintRes(v);
}

void KosarajuSharir() //solve
{
	memset(avail, true, sizeof(avail));
	up(i, 1, n + 1)
	if (avail[i]) DFS(i);
	memset(avail, true, sizeof(avail));
	while (!s.empty())
	{
		u = s.top(), s.pop();
		if (avail[u]) PrintRes(u), cout << '\n';
	}
}

void enter()
{
	cin >> n >> m;
	up(i, 0, m)
	{
		cin >> u >> v;
		adjf[u].push_back(v);
		adjb[v].push_back(u);
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
    KosarajuSharir();

    #ifdef QuanPham
    auto end = chrono::steady_clock::now();
    cerr << "In milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << '\n' << "In seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count() << '\n';
    #endif
    return 0;
}
