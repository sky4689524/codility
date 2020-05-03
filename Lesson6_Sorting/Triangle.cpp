int solution(vector<int> &A) {
	
	sort(A.begin(), A.end());
	long temp = 0;

	if (A.size() < 3)
		return 0;

	for (int i = 0; i < A.size() - 2; i++) {

		if (A[i] < 0)
			continue;

		temp = A[i] + A[i + 1] - A[i + 2];

		if (temp > 0)
			return 1;

	}

	return 0;
}

