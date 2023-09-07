ll get_hash(string &s)
{
	ll hash = 0;
	for (auto &it : s)
	{
		hash = (hash * 31 + (it - 'a' + 1)) % mod;
	}
	return hash;
}