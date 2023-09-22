#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node*arr[26] = {NULL};
	bool flag = false;
};

class Trie {
private:
	Node*root;

public:

	Trie() {
		root = new Node();
	}

	void insert(string &s)
	{
		int n = s.size();
		Node*node = root;

		for (int i = 0; i < n; i++)
		{
			if (!node->arr[s[i] - 'a'])
			{
				node->arr[s[i] - 'a'] = new Node();
			}
			node = node->arr[s[i] - 'a'];
		}

		node->flag = true;
	}

	bool searchString(string &s)
	{
		int n = s.size();
		Node*node = root;

		for (int i = 0; i < n; i++)
		{
			if (!node->arr[s[i] - 'a'])
			{
				return false;
			}
			node = node->arr[s[i] - 'a'];
		}

		if (node->flag == true) return true;
		return false;
	}

	bool searchPrefix(string &s)
	{
		int n = s.size();
		Node*node = root;

		for (int i = 0; i < n; i++)
		{
			if (!node->arr[s[i] - 'a'])
			{
				return false;
			}
			node = node->arr[s[i] - 'a'];
		}

		return true;
	}

};

void solve()
{
	int q;
	cin >> q;

	/*
		q={1, 2, 3};
		1-> insert a string
		2-> search a string
		3-> search a prefix
	*/

	Trie trie;

	/*
	1
	0
	1
	0
	*/


	while (q--)
	{
		int t;
		cin >> t;

		string s;
		cin >> s;

		if (t == 1)
		{
			trie.insert(s);
		}
		else if (t == 2)
		{
			cout << trie.searchString(s) << endl;
		}
		else if (t == 3)
		{
			cout << trie.searchPrefix(s) << endl;
		}
	}



}


int main() {

	solve();

	return 0;
}