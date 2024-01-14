vector<int>segtree;

//index is for segment tree, start, end and pos are for arr

void build(vector<int>&arr, int start, int end, int index) { //O(n)
    if (start == end) {
        segtree[index] = arr[start];
        return;
    }

    int mid = (start + end) >> 1;
    int left = 2 * index, right = 2 * index + 1;

    build(arr, start, mid, left);
    build(arr, mid + 1, end, right);

    segtree[index] = segtree[left] + segtree[right];
}

//update val at position pos to value
void update(vector<int>&arr, int start, int end, int index, int pos, int value) { //O(logn)
    if (start == end) {
        arr[pos] = value;
        segtree[index] = arr[pos];
        return ;
    }

    int mid = (start + end) >> 1;

    if (mid >= pos) { //left part to be updated?
        update(arr, start, mid, 2 * index, pos, value);
    }
    else {
        update(arr, mid + 1, end, 2 * index + 1, pos, value);
    }

    segtree[index] = segtree[2 * index] + segtree[2 * index + 1];
}

//query for range l to r
int query(int start, int end, int index, int l, int r) { //O(log n)

    //complete overlap
    if (start >= l && end <= r) {
        return segtree[index];
    }

    //disjoint
    if (l > end || start > r) {
        return 0;
    }

    //partial overlap

    int mid = (start + end) >> 1;


    int leftAns = query(start, mid, 2 * index, l, r);
    int rightAns = query(mid + 1, end, 2 * index + 1, l, r);


    return leftAns + rightAns;
}



void solve()
{
    int n;
    cin >> n;
    segtree.resize(4 * n);
    vector<int>arr(n);
    cin >> arr;


// ip
// 8
// 1 2 3 4 5 6 7 8

    // op
    // 6
    // 7


    //considering one-based indexing
    // if curr=1, left=2, right=3
    // as left=2*curr, right=2*curr+1;

    build(arr, 0, n - 1, 1);

    deb(arr);
    deb(segtree);

    cout << query(0, n - 1, 1, 0, 2) << line;


    //udpating val at index 1 to 3
    update(arr, 0, n - 1, 1, 1, 3);
    deb(arr);
    deb(segtree);
    cout << query(0, n - 1, 1, 0, 2) << line;

}
