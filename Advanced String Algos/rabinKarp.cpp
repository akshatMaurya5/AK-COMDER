ll compute_hash(const string &s, ll n) {
     ll hash = 0;
     ll prime = 31;
     ll p = 1;

     for (ll i = 0; i < n; i++) {
          ll x = s[i] - 'a' + 1;

          hash = (hash + (x * p) % mod) % mod;
          p = (p * prime) % mod;
     }
     return hash;
}


vector<ll>rabinKarp(string s, string pattern)
{
     ll n1 = pattern.size();
     ll n2 = s.size();

     // computing hash for the first window
     ll hash = compute_hash(s, n1);

     ll patternHash = compute_hash(pattern, n1);

     vector<ll> ans;
     if (hash == patternHash) {
          ans.push_back(0);

          //can check like for first pattern, without this, getting WA on CSES
          // if (s.substr(0, n1) == pattern) ans.push_back(0);

     }

     ll left = 0, right = n1 - 1;


     vector<ll>powers(n2 + 1, 0);

     ll prime = 31;
     ll p = 1;

     for (auto &it : powers) {
          it = p;
          p = (p * prime) % mod;

          // cerr << it << " ";
     }

     while (right < n2) {
          right++;

          hash = (hash + ((s[right] - 'a' + 1) * powers[right]) % mod) % mod;
          hash = (hash + mod) % mod; 

          hash = (hash - ((s[left] - 'a' + 1) * powers[left]) % mod) % mod;
          hash = (hash + mod) % mod; 

          left++;

          patternHash = (patternHash * 31) % mod;

          if (patternHash == hash) {
               ans.push_back(left);
          }
     }

     return ans;
}
