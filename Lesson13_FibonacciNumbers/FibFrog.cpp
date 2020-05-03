// reference : https://www.martinkysel.com/codility-fibfrog-solution/

int Fib(int M) {

	if (M == 0)
		return 0;

	else if (M == 1)
		return 1;

	else
		return Fib(M - 1) + Fib(M - 2);

}

int solution(vector<int> &A)
{
	int N = A.size();
	vector<int> fib; // fibonacci array 
	set<int> positions; // position array

	fib.push_back(1); // f(1) == 1
	fib.push_back(1); // f(2) == 1

	// save fibonacci numbers until the legth of river
	while (fib[fib.size() - 1] <= N + 1){
		fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
	}

	
	positions.insert(N);

	for (int count = 1; ; count++)
	{
		set<int> indexes;

		for (int i : positions)
		{

			for (int f : fib)
			{

				int pos = i - f;
				if (pos == -1)
					return count;
				if (pos < 0)
					break;
				if (A[pos])
					indexes.insert(pos);
			}
		}

		if (indexes.size() == 0)
			return -1;

		positions = indexes;
	}

	return -1;
}
