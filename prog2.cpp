long long canComplete(vector<int>&time, int m)
{
    long long int totalTrips = 0;

    for (auto &it : time)
    {
        totalTrips += (m / it);
    }
    // cout<<totalTrips<<" ";
    return totalTrips;
}

long long minimumTime(vector<int>& time, int totalTrips)
{
    long long int l = 1;
    long long int h = 1e14;
    long long ans;
    while (l < h)
    {
        long long int mid = l + (h - l) / 2;
        cout << l << endl;
        if (canComplete(time, mid) >= totalTrips) {
            ans = mid;
            hi = mid - 1;
            // h = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}


