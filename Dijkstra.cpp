#include    <bits/stdc++.h>
#define     ll long long
#define     pll pair <int, ll>
#define     X first
#define     Y second
#define     up(i, k, n) for (int i = k ; i < n ; i ++)
const int maxM = (int) 1e5 + 7;
const ll inf = (ll) 1e16;

using namespace std;

struct cmp
{
    bool operator () (const pll& a, const pll& b)
    {
        return a.Y > b.Y;
    }
};

ll m, n, d[maxM], u, v, w, du, s; vector <pll> adj[maxM];
priority_queue<pll, vector <pll>, cmp > pq;

inline void enter()
{
    cin >> n >> m;
    up(i, 0, m)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> s;
}

inline void Dijkstra(int s)
{
    fill_n(d, n + 1, (ll) inf);
    d[s] = 0;
    pq.push({s, 0});
    while (!pq.empty())
    {
        u = pq.top().X, du = pq.top().Y;
        pq.pop();
        if (du > d[u]) continue;
        for (auto i : adj[u])
        {
            v = i.X, w = i.Y;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({v, d[v]});
            }
        }
    }
    up(i, 1, n + 1) if (i != s) cout << (d[i] == inf ? -1 : d[i]) << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    enter();
    Dijkstra(s);

    return 0;
}
