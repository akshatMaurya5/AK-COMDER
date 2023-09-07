ll dp[2][11][11][11][22][2];

ll solve(string &s, ll tight = 1, ll idx = 0, ll odd = 0, ll even = 0, ll sum = 0, ll zero = 1)
{
    if (idx == s.size())
    {
        return !zero && sum == 0 && odd == even;
    }

    if (dp[tight][idx][odd][even][sum][zero] != -1) return dp[tight][idx][odd][even][sum][zero];

    int ans = 0;
    int limit = (tight ? s[idx] - '0' : 9);

    if (zero) {
        ans = solve(s, 0, idx + 1, odd, even, sum, zero);
    }

    for (ll d = 0; d <= limit; d++)
    {
        ll newTight = (tight && (d == s[idx] - '0'));
        ll newOdd = odd + (d & 1);
        ll newEven = even + ((!zero || d > 0) && d % 2 == 0);

        if (zero && d != 0) {
            ans += solve(s, newTight, idx + 1, newOdd, newEven, d, false);
        }
        else if (!zero) {
            ans += solve(s, newTight, idx + 1, newOdd, newEven, (sum * 10 + d) % k, false);
        }
    }

    return dp[tight][idx][odd][even][sum][zero] = ans;
}




//subtract one from low if low is given as string
//how to use: string one="1";
// low=findDiff(low, one);
bool isSmaller(string &str1, string &str2)
{
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}

string findDiff(string &str1, string &str2)
{
    if (isSmaller(str1, str2))
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;


    for (int i = 0; i < n2; i++)
    {
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    for (int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    reverse(str.begin(), str.end());

    return str;
}