#include <bits/stdc++.h>

using namespace std;

int n, a[100007], v, m;

int BS(int v)
{
    int l = 0, r = n + 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] < v) l = mid + 1;
        else            r = mid - 1;
    }
    if (l <= n && a[l] == v) return l;
    else return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("BSEARCH.INP", "r", stdin);
    freopen("BSEARCH.OUT", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1 ; i <= n ; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    a[0] = INT_MIN; a[n + 1] = INT_MAX;

    for (int i = 0 ; i < m ; i ++)
    {
        scanf("%d", &v);
        if (BS(v) != -1) printf("YES\n");
        else printf("NO\n");
    }
}
