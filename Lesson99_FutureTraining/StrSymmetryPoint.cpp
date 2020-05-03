// find a symmetry point of a string, if any.
int solution(string &S) {

	int N = S.size();
	int mid = 0;

	if (N % 2 == 0)
		return -1;

	mid = N / 2;

	for (int i = 0; i < mid; i++) {
		if (S[i] != S[N - i - 1])
			return -1;
	}

	return mid;
}
