int solution(vector<int> &A) {

	int N = A.size();
	int count = 0;

	sort(A.begin(), A.end());

	for (int p = 0; p < N; p++) {

		int r = p + 2;

		for (int q = p + 1; q < N; q++) {

			while (r < N && A[p] + A[q] > A[r])
				r++;

			count += r - q - 1;

		}

	}


	return count;

}
