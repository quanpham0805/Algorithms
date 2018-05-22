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
#define     QuanPham
const int maxN = (int) 1e4 + 7;
const int maxM = (int) 1e5 + 7;
const int maxT = (int) 1e6 + 7;
const int SIZE = (int) 26;

using namespace std;

struct TrieNode
{
	struct TrieNode *children[SIZE];
	bool isEnd;
};

struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isEnd = false;
	up(i, 0, SIZE) pNode->children[i] = NULL;
	return pNode;
}

void Insert(struct TrieNode *root, string key)
{
	struct TrieNode *parent = root;
	up(i, 0, key.length())
	{
		int id = key[i] - 'a';
		if (!parent->children[id]) parent->children[id] = getNode();
		parent = parent->children[id];
	}
	parent->isEnd = true;
}

bool search(struct TrieNode *root, string key)
{
	struct TrieNode *parent = root;
	up(i, 0, key.length())
	{
		int id = key[i] - 'a';
		if (!parent->children[id]) return false;
		parent = parent->children[id];
	}
	return parent != NULL && parent->isEnd;
}

void PrintWords(struct TrieNode *root, char str[], int id)
{
	if (root->isEnd)
	{
		str[id] = '\0';
		cout << str << '\n';
	}
	up(i, 0, SIZE)
	if (root->children[i])
	{
		str[id] = i + 'a';
		PrintWords(root->children[i], str, id + 1);
	}
}

bool checkForDeleting(struct TrieNode *root)
{
	int cnt = 0;
	up(i, 0, SIZE)
	if (root->children[i]) cnt ++;
	return cnt == 0;
}

void Del(struct TrieNode *root, string key, int level)
{
	if (level == key.length()) return;
	int id = key[level] - 'a';
	Del(root->children[id], key, level + 1);
	if (checkForDeleting(root->children[id]))
	{
		root->children[id] = NULL;
		delete root->children[id];
	}
}

void Init()
{
	int n; struct TrieNode *root = getNode();
	string keys[] = {"i", "love", "nguyen", "ha", "phuong", "abcde", "ggwp"};
	string toDel[] = {"abcde", "ggwp", "others"};

	//inserting
	n = 7;
	up(i, 0, n) Insert(root, keys[i]);
	cout << '\n';

	//searching
	if (search(root, "phuong")) cout << "Quan\n";
	else cout << "-1\n";
	if (search(root, "ng")) cout << "X\n";
	else cout << "-1\n";
	cout << '\n';

	//printing
	int id = 0, char_size = 30;//sizeof longest string
	char str[char_size];
	PrintWords(root, str, id);
	cout << '\n';

	//deleting
	int q = 3;
	up(i, 0, q)
	if (search(root, toDel[i])) Del(root, toDel[i], 0);
	PrintWords(root, str, 0);//to check
	cout << '\n';
}

int main()
{
    #ifdef QuanPham
    auto start = chrono::steady_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen ("TRIE.INP", "r", stdin);
    //freopen ("TRIE.OUT", "w", stdout);

    Init();

    #ifdef QuanPham
    auto end = chrono::steady_clock::now();
    cerr << "In milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << '\n' << "In seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count() << '\n';
    #endif
    return 0;
}
