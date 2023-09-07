

void solve()
{
	string s;
	cin >> s;
	string bad;
	cin >> bad;

	ll k;
	cin >> k;


	set<pii>st;

	ll n = sz(s);

	ll prime1 = 31;
	ll prime2 = 27;


	f(i, 0, n)
	{
		ll pos1 = 1;
		ll pos2 = 1;
		ll hash1 = 0;
		ll hash2 = 0;
		ll b = 0;

		f(j, i, n)
		{
			ll x = s[j] - 'a';

			if (bad[x] == '0')
			{
				b++;
			}

			if (b > k) {
				break;
			}

			hash1 = ( hash1 + ((x + 1) * pos1) % mod) % mod;
			hash2 = ( hash2 + ((x + 1) * pos2) % mod) % mod;


			pos1 = (pos1 * prime1) % mod;
			pos2 = (pos2 * prime2) % mod;

			st.insert({hash1, hash2});



		}
	}
	cout << sz(st) << line;

}
