// QUESTION -> FIND THE SUM BETWEENT THE GIVEN RANGE

#include <bits/stdc++.h>
using namespace std;

class segTree {

    vector<int>seg;

public:

    segTree(int n) {
        seg.resize(4 * n);
    }

    void build(int idx, int low, int high, vector<int>&arr) {
        if (low == high)
        {
            seg[idx] = arr[low];
            return ;
        }
        int mid = (high + low) / 2;

        build(2 * idx + 1 , low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        //we keep on changing this line acc to our need
        seg[idx] = seg[2 * idx + 1 ] + seg[2 * idx + 2  ];
    }

    void printSeg()
    {
        for (auto &it : seg)
        {
            cout << it << " ";
        }
    }

    int query(int idx, int low, int high, int l, int r)
    {
        // no overlap
        if (r < low || high < l) return 0;

        //COMPLETE OVERLAP

        if (low >= l  && high <= r) return seg[idx];

        int mid = (low + high) >> 1;
        int left = query(2 * idx + 1, low, mid,  l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);

        return seg[idx] = left + right;
    }


};


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr = {5, 3, 2, 4, 1, 8, 6, 10};
    int n = arr.size();

    segTree st(n);

    st.build(0, 0, n - 1, arr);
    // cout << "here";
    // st.printSeg();


    //input
    // 1
    // 1 5
    // - 1
    while (true)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r;
            cin >> l >> r;

            int ans = st.query(0, 0, n - 1, l, r);
            cout << ans << endl;

        }
        else if (type == -1)
        {
            break;
        }

    }



    return 0;
}

