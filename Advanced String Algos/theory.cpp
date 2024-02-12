#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
you are given a string and ranges l1, r1, l2, r2

check if s(l1, r1) = s(l2, r2);

i.e substring b/w these ranges are equal


EXPLANATION:

let prime taken be 31

    0           1             2              3                 4
s=" a           a             b              a                 a"
   1x(31)^0    1x(31)^0+     1x(31)^0+      1x(31)^0+       1x(31)^0+
               1X(31)^1      1X(31)^1       1X(31)^1        1X(31)^1
                             2X(31)^2       2X(31)^2        2X(31)^2
                                            1X(31)^3        1X(31)^3
                                                            1x(31)^4


we will make prefix of hash and solve the task

let range be [0, 1]  [3, 4]

till 1 => 1x(31)^0 + 1x(31)^1

prefix till 2 ==>
1x(31)^0+1x(31)^1+2x(31)^2

when we minus

after subtraction we get : 1x(31)^3 + 1x(31)^4 ;





*/


void solve()
{

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}


