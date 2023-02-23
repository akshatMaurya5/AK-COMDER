#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << "=" << x <<'\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;


void traverse(TreeNode*root)
{
	stack<pair<TreeNode*, int>>st;
	st.push({root, 1});
	vector<int>pre, post, in;

	while (!st.empty())
	{
		auto it = st.top();
		st.pop();

		if (it.second == 1)
		{
			pre.push_back(it.first->val);
			it.second++;
			st.push(it);

			if (it.first->left)
			{
				st.push({it.first->left, 1});
			}
		}
		else if (it.second == 2)
		{
			in.push_back(it.first->val);
			it.second++;
			st.push(it);

			if (it.first->right)
			{
				st.push({it.first->right, 1});
			}
		}
		else // dont push again
		{
			post.push_back(it.first->val);
		}


	}


}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}