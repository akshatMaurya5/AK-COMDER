#include <bits/stdc++.h>
using namespace std;


// When is a destructor called?
// A destructor function is called automatically when:
// ➔ the object goes out of scope
// ➔the program ends
// ➔a scope (the { } parenthesis) containing local variable ends.
//  ➔a delete operator is called


class dest {
public:
	dest()
	{
		cout << "Welcome\n";
		cout << "constructor is called\n";
	}

	~dest()
	{
		cout << "BYE\n";
		cout << "desctuctor is called\n";
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	dest obj;


	return 0;
}