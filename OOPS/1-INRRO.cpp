#include <bits/stdc++.h>
using namespace std;


//PUBLIC PRIVATE PROTECTED ARE CALLED ACCESS SPECIFIERS

class noob {
public:
	int a, b;

	// noob(int _a, int _b)
	// {
	// 	a = _a;
	// 	b = _b;
	// }

	void __print()
	{
		cout << "value of a is:" << a << endl;
		cout << "value of b is:" << b << endl;
	}

};


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	// noob noobie(6, 9);

	noob noobie;

	noobie.a = 5;
	noobie.b = 55;


	noobie.__print();

	return 0;
}

