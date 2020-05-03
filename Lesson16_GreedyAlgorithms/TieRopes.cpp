int solution(int K, vector<int> &A) {

	int N = A.size();
	int count = 0;
	int length = 0;

	for (int i = 0; i < N; i++) {

		length += A[i];

		if (length >= K) {
			count++;
			length = 0;
		}

	}

	return count;

}
