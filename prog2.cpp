#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	// Calculate 2^n modulo MOD using fast exponentiation
	long long power = 1;
	for (int i = 0; i < n; i++) {
		power = (power * 2) % MOD;
	}

	cout << power << "\n";
	return 0;
}
