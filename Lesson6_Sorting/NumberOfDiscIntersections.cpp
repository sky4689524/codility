// reference : https://stackoverflow.com/questions/4801242/algorithm-to-calculate-number-of-intersecting-discs

int solution(vector<int> &A) {
	
	vector<int> count(A.size());
	int a = 0, S = 0, t = 0;
	int N = A.size();

	// Mark left and middle of disks
	for (int i = 0; i < N; i++) {
		count[i] = -1;

		a = A[i];

		if (a >= i)
			count[0]++;
		else
			count[i - a]++;
	}

	// Sum of left side of disks at location
	for (int i = 0; i < N; i++) {
		t += count[i];
		count[i] = t;
	}

	// Count pairs, right side only:
	// 1. overlaps based on disk size
	// 2. overlaps based on disks but not centers

	for (int i = 0; i < N; i++) {
		a = A[i];
		S += ((a < N - i) ? a : N - i - 1);
		if (i != N - 1) {

			S += count[((a < N - i) ? i + a : N - 1)];
		}
		if (S > 10000000)
			return -1;
	}
	return S;
}
