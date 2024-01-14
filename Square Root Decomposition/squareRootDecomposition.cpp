#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> blocks;
ll blockSize;
vector<ll> dummy;

void init(ll n, vector<ll> &v)
{
     dummy = v;
     blockSize = sqrt(n);
     blocks.resize(blockSize);

     ll blockIdx = -1;

     for (ll i = 0; i < n; i++)
     {
          if (i % blockSize == 0)
          {
               blockIdx++;
          }
          blocks[blockIdx] += dummy[i];
     }
}

void update(ll idx, ll val)
{
     ll blockNum = idx / blockSize;

     blocks[blockNum] += val - dummy[idx];

     dummy[idx] = val;
}

ll query(ll l, ll r)
{
     ll sum = 0;

     while (l < r && l % blockSize != 0 && l != 0)
     {
          sum += dummy[l];
          l++;
     }

     while (l + blockSize - 1 <= r)
     {
          sum += blocks[l / blockSize];
          l += blockSize;
     }

     while (l <= r)
     {
          sum += dummy[l];
          l++;
     }

     return sum;
}

void solve()
{
     vector<ll> v = { 1, 5, 2, 4, 6, 1, 3, 5, 7, 10 };

     ll n = v.size();

     init(n, v);

     cout << "query(3,8) : " << query(3, 8) + << endl;
     cout << "query(1,6) : " << query(1, 6) + << endl;
     update(8, 0);
     cout << "query(8,8) : " << query(8, 8) + << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
     freopen("..input.txt", "r", stdin);
     freopen("..error.txt", "w", stderr);
     freopen("..output.txt", "w", stdout);
#endif

     ios::sync_with_stdio(0);
     cin.tie(0);
     solve();
     return 0;
}
