#include    <bits/stdc++.h>

const int SIZE = 26;
const bool TO_LOWER = false;
const bool TO_UPPER = true;

using namespace std;

struct Trie {
	Trie* children[SIZE];
	bool isEnd;

	Trie() {
		this->isEnd = false;

		for (int i = 0 ; i < SIZE ; i ++)
			this->children[i] = nullptr;
	}
};

int lowerCaseCharToInt(char c) {
	return c - 'a';
}

int upperCaseCharToInt(char c) {
	return c - 'A';
}

int charToInt(char c) {
	return ('a' <= c && c <= 'z') ? lowerCaseCharToInt(c) : upperCaseCharToInt(c);
}

char intToLowerCaseChar(int i) {
	return i + 'a';
}

char intToUpperCaseChar(int i) {
	return i + 'A';
}

char intToChar(int i, bool upperOrLower) {
	return upperOrLower ? intToUpperCaseChar(i) : intToLowerCaseChar(i);
}

void insert(Trie* trie, string value) {
	Trie* currentNode = trie;

	for (auto charInString : value) {
		int keySlot = charToInt(charInString);

		if (!currentNode->children[keySlot])
			currentNode->children[keySlot] = new Trie();

		currentNode = currentNode->children[keySlot];
	}
	currentNode->isEnd = true;
}


bool search(Trie* trie, string value) {
	Trie* currentNode = trie;

	for (auto charInString : value) {
		int keySlot = charToInt(charInString);
		if (!currentNode->children[keySlot])
			return false;
		currentNode = currentNode->children[keySlot];
	}
	return currentNode->isEnd;
}

void printAll(Trie* trie, string accumulator = "") {
	if (trie->isEnd)
		cout << accumulator << '\n';

	for (int i = 0 ; i < SIZE ; i ++)
		if (trie->children[i]) {
			accumulator.push_back(intToChar(i, TO_LOWER));
			printAll(trie->children[i], accumulator);
			accumulator.pop_back();
		}
}

bool emptyNode(Trie* trie) {
	int childrenCount = 0;

	for (int i = 0 ; i < SIZE ; i ++)
		if (trie->children[i])
			childrenCount ++;

	return childrenCount == 0;
}

void deletion(Trie* trie, string value, int index = 0) {
	if (index == value.length())
		return;

	int keySlot = charToInt(value[index]);
	deletion(trie->children[keySlot], value, index + 1);
	if (emptyNode(trie->children[keySlot]))
		delete trie->children[keySlot], trie->children[keySlot] = nullptr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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
	if (search(root, toDel[i]))
		deletion(root, toDel[i]);
	printAll(root);//to check
	cout << '\n';

    return 0;
}

