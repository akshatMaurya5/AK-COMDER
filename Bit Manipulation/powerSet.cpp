#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vi v = {1, 2, 3};
    int n = v.size();

    int last = (1 << n) - 1;
    //for n==3, there will be 8 combos, idxs will be from 0 to 7

    for (int num = 0; num <= last; num++)
    {

        for (int bit = 0; bit <= n - 1; bit++)
        {
            if (num & (1 << bit))
            {
                cout << v[bit] << " ";
            }
        }
        cout << endl;
    }


    return 0;
}