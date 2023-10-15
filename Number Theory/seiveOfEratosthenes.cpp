int N;

vector<bool>seive;

void SOE()
{

	seive[0] = seive[1] = false;

	for (int i = 2; i * i < N; i++)
	{
		if (seive[i] == true) // mark it's multiples
		{
			for (int j = i * i; j <= N; j += i)
			{
				seive[j] = false;
			}
		}
	}

}