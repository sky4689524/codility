vector<int> solution(int N, vector<int> &A) {

	vector<int> counter(N, 0);
	int maximum_value = 0;
	int base = 0;

	for (int i = 0; i < A.size(); i++) {

		if (A[i] > N) {

			base = maximum_value;

		}
		else {

			counter[A[i] - 1] = max(base, counter[A[i] - 1 ]) + 1;

			maximum_value = max(maximum_value, counter[A[i] - 1]);

		}

	}

	for (int i = 0; i < N; i++) {
		if (counter[i] < base)
			counter[i] = base;
	}

	return counter;

}
