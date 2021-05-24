#include    <bits/stdc++.h>

using namespace std;

struct Trie {
	map <char, Trie*> children;
	bool isEnd;

	Trie() {
		this->isEnd = false;
	}
};

void insert(Trie* trie, string value) {
	for (auto charInString : value) {
		if (trie->children.find(charInString) == trie->children.end())
			trie->children[charInString] = new Trie();

		trie = trie->children[charInString];
	}
	trie->isEnd = true;
}


bool search(Trie* trie, string value) {
	for (auto charInString : value) {
		if (trie->children.find(charInString) == trie->children.end())
			return false;

		trie = trie->children[charInString];
	}
	return trie->isEnd;
}

void printAll(Trie* trie, string accumulator = "") {
	if (trie->isEnd)
		cout << accumulator << '\n';

	for (auto key : trie->children) {
		accumulator.push_back(key.first);
		printAll(trie->children[key.first], accumulator);
		accumulator.pop_back();
	}
}

bool emptyNode(Trie* trie) {
	return trie->children.size() == 0;
}

void deletionHelper(Trie* trie, string value, int index = 0) {
	if (index == value.length())
		return;

	deletionHelper(trie->children[value[index]], value, index + 1);
	if (emptyNode(trie->children[value[index]])) {
		delete trie->children[value[index]];
		trie->children[value[index]] = nullptr;
		trie->children.erase(value[index]);
	}
}

void deletion(Trie* trie, string value) {
	if (search(trie, value))
		deletionHelper(trie, value);
}

void example() {
	int n; Trie *root = new Trie();
    string keys[] = {"i", "love", "one", "two", "three", "abcde", "ggwp"};
	string toDel[] = {"abcde", "ggwp", "others"};

	cout << "-----------\n";
	//inserting
	n = 7;
	for (int i =  0 ; i < n ; i ++) insert(root, keys[i]), printAll(root), cout << "\n\n";
	cout << "-----------\n";


	//searching
	if (search(root, "one")) cout << "1\n";
	else cout << "-1\n";
	if (search(root, "ng")) cout << "1\n";
	else cout << "-1\n";
	cout << "-----------\n";
	printAll(root);
	cout << "-----------\n";

	//deleting
	int q = 3;
	for (int i = 0 ; i < q ; i ++)
		deletion(root, toDel[i]);
	printAll(root);//to check
	cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    example();

    return 0;
}