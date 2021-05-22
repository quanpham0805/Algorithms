#include    <bits/stdc++.h>
#define     up(i, k, n) for (int i = k ; i < n ; i ++)
const int maxM = (int) 2e5 + 7;

using namespace std;

int n, m, cc, r, s, lab[maxM], u[maxM], v[maxM];

void MakeSet(int u)
{
	lab[u] = -1;
}

int FindSet(int u)
{
	return lab[u] < 0 ? u : lab[u] = FindSet(lab[u]);
}

void Union(int r, int s)
{
	if (lab[s] < lab[r]) swap (r, s);
	lab[r] += lab[s];
	lab[s] = r;
}

void solve()
{
	up(u, 1, n + 1) MakeSet(u);
	cc = n;
	up(i, 0, m)
	{
		r = FindSet(u[i]), s = FindSet(v[i]);
		if (r != s) Union(r, s), cc --;
		cout << cc << '\n';
	}
}

void enter()
{
	cin >> n >> m;
	up(i, 0, m) cin >> u[i] >> v[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    enter();
    solve();
}
