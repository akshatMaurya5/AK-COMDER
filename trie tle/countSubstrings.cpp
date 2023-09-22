#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node*arr[26] = {NULL};
	bool flag = false;
};

void solve()
{
	string s;
	cin >> s;

	Node*root = new Node();
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		Node*node = root;

		for (int j = i; j < s.size(); j++)
		{
			if (!node->arr[s[i] - 'a']) {
				cnt++;
				node->arr[s[i] - 'a'] = new Node();
			}
			node = node->arr[s[i] - 'a'];
		}
	}

	cout << cnt + 1;

}
int main() {

	solve();

	return 0;
}