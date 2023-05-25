#include <bits/stdc++.h>
using namespace std;

class test {
private:
	string course;
	int marks;
public:
	test()
	{
		course = "unknown";
		marks = 69;
	}

	test(string sub="noob", int _marks)
	{
		course = sub;
		marks = _marks;
	}


	void print()
	{
		cout << course << " ";
		cout << marks;
		cout << endl;
	}
};


int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("error.txt", "w", stderr);
// 	freopen("output.txt", "w", stdout);
// #endif

	test test1;
	test test2("", 100);

	test1.print();
	test2.print();

	return 0;
}