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
const int maxN = (int) 1e4 + 7;
const int maxM = (int) 1e5 + 7;
const int maxT = (int) 3e6 + 7;

using namespace std;

static int n, a[maxT], b[maxT][26], node, q;
static bool isEnd[maxT];

void ins(string &s)
{
    int root = 0;
    for (auto i : s)
    if (b[root][i] == 0)
    {
        node ++;
        a[node] = i;
        root = b[root][i] = node;
    }
    else root = b[root][i];
    isEnd[root] = true;
}

bool Find(string &s)
{
    int root = 0;
    for (auto i : s)
    if (b[root][i] != 0) root = b[root][i];
    else return false;
    return isEnd[root];
}

void solve()
{
    cin >> q;
    while (q --)
    {
        string p;
        cin >> p;
        cout << (Find(p) ? "In\n" : "Out\n");
    }
}

void enter()
{
    cin >> n;
    up(i, 0, n)
    {
        string s;
        cin >> s;
        ins(s);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    enter();
    cout << node + 1;
    //solve();

    return 0;
}
