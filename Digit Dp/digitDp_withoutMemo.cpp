#include <bits/stdc++.h>
using namespace std;
// given range L to R. Find the total numbers where digit d occurs k time
/*
To find answer we use the technique used in prefix sum

we will find the numbers satisfying condition which are less than or equal to R --> ansR
we will find the numbers satisfying condition which are less than or equal to L-1 --> ansL

finalAnswer= ansR-ansL;


now dp states -> idx flag and cnt are changing

idx can go upto R ie for a number of 1e18 R will be 18
flag will be of size 2
cnt will be equal to size of idx --> ie when the whole number comprises of digit k -->(kkkkk..k)

therefore size of dp will me [19][2][19]

*/




int l, r, d, k;

int solve(int idx, int flag, int cnt, vector<int>&num)
{
	if (idx == num.size()) {
		if (cnt == k) return 1;
		else return 0;
	}

	int limit = num[idx];

	// if flag==1 -=> then it means that the number is smaller and now i can fill digits upto 90

	if (flag == 1) {
		limit = 9;
	}

	int count = 0;

	for (int digit = 0; digit <= limit; digit++)
	{
		if (flag == 1)
		{
			if (digit == d) {
				count += solve(idx + 1, flag, cnt + 1, num);
			}
			else {
				count += solve(idx + 1, flag, cnt, num);
			}
		}
		else if (flag == 0)
		{
			if (digit == d)
			{
				if (digit < num[idx]) count += solve(idx + 1, 1, cnt + 1, num);
				else count += solve(idx + 1, 0, cnt + 1, num);
			}
			else {
				if (digit < num[idx]) count += solve(idx + 1, 1, cnt, num);
				else count += solve(idx + 1, 0, cnt, num);
			}
		}
	}

	return count;
}

vector<int>convertIntoDigits(int n)
{
	vector<int>ans;

	while (n) {
		ans.push_back(n % 10);
		n /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

void digitDP()
{
	cin >> l >> r >> d >> k;


	//for RIGHT
	vector<int>num = convertIntoDigits(r);
	int ansR = solve(0, 0, 0, num);


	//for LEFT
	num = convertIntoDigits(l - 1);
	int ansL = solve(0, 0, 0, num);


	cout << ansR - ansL << endl;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	digitDP();

	return 0;
}