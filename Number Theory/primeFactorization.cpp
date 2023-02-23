#include <bits/stdc++.h>
using namespace std;

void brute(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;

            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            cout << i << " ^ " << cnt << endl;
        }
    }
}

void optimal(int n) // run loop till sqrt(n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;

            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            cout << i << " ^ " << cnt << endl;
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
    brute(100);
    // optimal(100);
    return 0;
}