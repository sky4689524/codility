vector<int> solution(vector<int> &A) {

	int N = A.size();
	vector<int> division_count(N);
	vector<int> each_count(*std::max_element(A.begin(), A.end()) + 1, 0);

	for (int i = 0; i < N; i++)
		each_count[A[i]]++;

	for (int i = 0; i < N; i++) {

		int divisor = 0;

		for (int j = 1; j * j<= A[i]; j++) {

			if (A[i] % j == 0) {

				divisor += each_count[j];

				if (A[i] / j != j) {

					divisor += each_count[A[i] / j];
				}

			}
		}


		division_count[i] = N - divisor;


	}


	return division_count;

}
