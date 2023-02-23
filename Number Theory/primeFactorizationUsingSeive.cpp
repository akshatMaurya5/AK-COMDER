// question is to print the prime factors of the number

#include <bits/stdc++.h>
using namespace std;
int  N   = 10000;

//smallestPrimeFactor
vector<int> smallestPrimeFactor(N + 1);

void seive()
{
	for (int i = 1; i <= N; i++) {
		smallestPrimeFactor[i] = i;
	}

	for (int i = 2; i * i <= N ;  i++)
	{
		//if number is marked as itself then it is  prime
		if (smallestPrimeFactor[i] == i)
		{
			// now mark it's multiples

			for (int j = i * i; j <= N; j += i)
			{
				//if it is going to be marked for the first time then only place the ith prime at this position
				if (smallestPrimeFactor[j] == j)
				{
					smallestPrimeFactor[j] = i;
				}
			}

		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;


	/*

	TC -> nlogn  for seive and log n for the query

	*/

	while (n != 1)
	{
		cout << smallestPrimeFactor[n] << " ";
		n /= smallestPrimeFactor[n];
	}
	cout << endl;

	return 0;
}
