vector<long long>get_lps(string s)
{
    long long n = s.size();
    vector<long long>lps(n, 0);

    //prevLps is idx of lps array
    long long prevLps = 0, i = 1;

    while (i < n)
    {
        if (s[i] == s[prevLps]) {
            lps[i] = prevLps + 1;
            prevLps++;
            i++;
        }
        else if (prevLps == 0) {
            lps[i] = 0;
            i++;
        }
        else {
            prevLps = lps[prevLps - 1];
        }
    }
    return lps;
}

long long kmpSearch(string s, string pattern)
{
    long long n = s.size(), m = pattern.size();

    auto lps = get_lps(pattern);


    long long i = 0, j = 0, count = 0;
    vector<long long>idx_found;

    while (i < n) {
        if (pattern[j] == s[i]) {
            j++;
            i++;
        }

        if (j == m) {
            // Pattern found
            count++;
            idx_found.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return count;

}
