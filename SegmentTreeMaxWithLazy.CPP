/*
 *Update: update a segment of array
 *Query: Query max from 1 segment of array
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
    int lef, rig, lazy, val;
    NodeData()
    {
        lazy = val = 0;
    }
 
    NodeData(int lef, int rig, int val)
    {
        this->lef = lef;
        this->rig = rig;
        this->val = val;
    }
};
 
NodeData tree[maxT];
static int m, n, a[maxT];
 
void BuildTree(int x, int l, int r)
{
    if (l > r) return;
    tree[x] = NodeData(l, r, -1);
    if (l == r) {tree[x] = NodeData(l, r, a[l]); return;}
 
    int mid = l + r >> 1;
    BuildTree(x * 2, l, mid);
    BuildTree(x * 2 + 1, mid + 1, r);
    tree[x].val = max(tree[x * 2].val, tree[x * 2 + 1].val);
 
}
 
void lazy(int x)
{
    tree[x * 2].val      += tree[x].lazy;
    tree[x * 2 + 1].val  += tree[x].lazy;
    tree[x * 2].lazy     += tree[x].lazy;
    tree[x * 2 + 1].lazy += tree[x].lazy;
    tree[x].lazy = 0;
}
 
void Update(int x, int l, int r, int k)
{
    lazy(x);
    if (r < tree[x].lef || l > tree[x].rig) return;
    if (l <= tree[x].lef && tree[x].rig <= r)
    {
        tree[x].lazy += k;
        tree[x].val += k;
        lazy(x);
        return;
    }
    Update(x * 2, l, r, k);
    Update(x * 2 + 1, l, r, k);
    tree[x].val = max(tree[x * 2].val, tree[x * 2 + 1].val);
}
 
int Query(int x, int l, int r)
{
    lazy(x);
    if (l > tree[x].rig || r < tree[x].lef) return -1;
    if (l <= tree[x].lef && tree[x].rig <= r) return tree[x].val;
    return max(Query(x * 2, l, r), Query(x * 2 + 1, l, r));
}
 
int main()
{
    #ifdef QuanPham
    auto start = chrono::steady_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> m;
    BuildTree(1, 1, n);
    while (m --)
    {
        int type, a, b, k;
        cin >> type >> a >> b;
        if (type == 1) cout << Query(1, a, b) << '\n';
        else cin >> k, Update(1, a, b, k);
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
