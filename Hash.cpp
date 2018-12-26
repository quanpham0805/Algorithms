/*
 * Author: Quan Pham
 * Find all occurrence of second string in the first string
 * Index start at 0
 * Hash implementation
 * Length of string <= 1e5
 * Idea of hashing http://vnoi.info/wiki/algo/string/hash
 * this implementation is a reusable code
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
const int nMod = 2;// number of modulo needed
const int mod[] = {1000000007, 999999983};// modulo, the more modulos the slower the code due to modulo
const int base = 653;// base for modulo

using namespace std;

struct Hash
{
	int val[nMod];
	Hash() {}
	Hash(int x)
	{
		up(i, 0, nMod) val[i] = x;// get value
	}
	Hash operator * (const Hash b) // for line 101 and 117
	{
		Hash res;
		up(i, 0, nMod)
		res.val[i] = (1LL * val[i] * b.val[i]) % mod[i];
		return res;
	}
	Hash operator * (const int b)// for line 87: creating power
	{
		Hash res;
		up(i, 0, nMod)
		res.val[i] = (1LL * val[i] * b) % mod[i];
		return res;
	}
	Hash operator + (const Hash b)// adding the hash values
	{
		Hash res;
		up(i, 0, nMod)
		res.val[i] = (val[i] + b.val[i]) % mod[i];
		return res;
	}
	Hash operator - (const Hash b)// subtracting the
	{
		Hash res;
		up(i, 0, nMod)
		res.val[i] = (((val[i] - b.val[i]) % mod[i]) + mod[i]) % mod[i];
		return res;
	}
	bool operator == (const Hash b) const// equal or not?
	{
		up(i, 0, nMod)
		if (val[i] != b.val[i]) return false;
		return true;
	}
} POW[maxM], Ha[maxM], Hb[maxM];
string s, p;

void enter()
{
	cin >> s >> p;
}

void Init()
{
	POW[0] = Hash(1);
	up(i, 1, maxM) POW[i] = POW[i - 1] * base;

	Ha[0] = Hash(s[0] - 'a' + 1);
	up(i, 1, s.length())
	Ha[i] = Ha[i - 1] * base + Hash(s[i] - 'a' + 1);// hash value of first string

	Hb[0] = Hash(p[0] - 'a' + 1);
	up(i, 1, p.length())
	Hb[i] = Hb[i - 1] * base + Hash(p[i] - 'a' + 1);// hash value of second string
}

Hash getA(const int l, const int r)
{
	if (l == 0) return Ha[r];
	return Ha[r] - Ha[l - 1] * POW[r - l + 1];// hash value from l to r of first string
}

Hash getB(const int l, const int r)
{
	if (l == 0) return Hb[r];
	return Hb[r] - Hb[l - 1] * POW[r - l + 1];// hash value from l to r of second string
}

void solve()
{
	int n = s.length(), m = p.length();
	up(i, 0, n)
	{
		if (i + m - 1 > n - 1) break;
		if (getB(0, m - 1) == getA(i, i + m - 1)) cout << i << ' ';
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
    Init();
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
