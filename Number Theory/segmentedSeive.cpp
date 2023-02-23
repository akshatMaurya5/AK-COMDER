/*
    FIND ALL THE PRIMES IN RANGE L TO R
    (L,R) -> 10^12
    R-L <= 10^6
*/


/*
1. find the primes which are less than R
2. create seive of size r-l+1
3. mark the factors of primes in range l to r
*/


#include <bits/stdc++.h>
using namespace std;

int N = 1e6;
vector<bool>seive(N + 1);

void createSeive()
{
    for (int i = 2; i <= N; i++)
    {
        seive[i] = true;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (seive[i])
        {
            for (int j = i * i; j <= N; j = +i)
            {
                seive[j] = false;
            }
        }

    }

}

vector<int>generatePrimes(int n) {
    vector<int>res;
    for (int i = 2; i <= n; i++)
    {
        if (seive[i])
        {
            res.push_back(i);
        }
    }

    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    createSeive();

    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        //step 1 - generate all primes till sqrt(R)
        vector<int>primes = generatePrimes(sqrt(r));

        //step 2 - create a dummy array of size r-l+1 and mark it as one

        vector<int>dummy(r - l + 1, 1);

        //step 3 - mark all multiples primes

        for (auto pr : primes)
        {
            int firstMultiple = (l / pr) * pr;

            if (firstMultiple < l) {
                firstMultiple += pr;
            }

            /*
            let l r be 110 to 150

            primes will be 2, 3, 5, 7, 9, 11

            2 will start marking from 110  and so on
            but 11 will start marking from 121
            */

            for (int j = max(firstMultiple, pr * pr); j <= r; j += pr)
            {
                dummy[j - l] = false;
            }

        }

        //step 4 - get all the primes

        for (int i = l; i <= r; i++)
        {
            if (dummy[i - l] == 1)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }



    return 0;
}

