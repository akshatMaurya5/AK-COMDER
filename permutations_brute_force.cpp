void generatePermutations(vector<vector<ll>>& result, vector<ll>& nums, ll start) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (ll i = start; i < nums.size(); ++i) {
        swap(nums[start], nums[i]);
        generatePermutations(result, nums, start + 1);
        swap(nums[start], nums[i]);
    }
}


void permute(ll n)
{
    vi v;
    for (ll i = 1; i <= n; i++)
    {
        v.pb(i);
    }

    vvi res;
    generatePermutations(res, v, 0);
}