// reference : https://rafal.io/posts/codility-max-double-slice-sum.html

// use Kadane's algorithm
int solution(vector<int> &A) {

	int N = A.size();
	int maxValue = 0;
	vector<int> K1(N);
	vector<int> K2(N);

	for (int i = 1; i < N - 1; i++) {
		K1[i] = max(K1[i - 1] + A[i], 0);
	}
	for (int i = N - 2; i > 0; i--) {
		K2[i] = max(K2[i + 1] + A[i], 0);
	}

	for (int i = 1; i < N - 1; i++) {
		maxValue = max(maxValue, K1[i - 1] + K2[i + 1]);
	}
	
	return maxValue;
}
