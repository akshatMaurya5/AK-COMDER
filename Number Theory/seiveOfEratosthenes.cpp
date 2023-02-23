#include <bits/stdc++.h>
using namespace std;

int N =  1e5;
vector<bool>seive(N, true);

void SOE(int n)
{

	seive[0] = seive[1] = false;

	for (int i = 2; i * i < n; i++)
	{
		if (seive[i] == true) // mark it's multiples
		{
			for (int j = i * i; j <= n; j += i)
			{
				seive[j] = false;
			}
		}
	}

	if (seive[n])
	{
		cout << "prime\n";
	}
	else
	{
		cout << "not prime";
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
	SOE(69);
	return 0;
}