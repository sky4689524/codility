// reference : https://hackernoon.com/kadanes-algorithm-explained-50316f4fd8a6

int solution(vector<int> &A) {

	int N = A.size();
	int maxValue = 0;
	vector<int> sum(N);

	sum[0] = A[0];
	maxValue = A[0];

	for (int i = 1; i < N; i++) {

		sum[i] = max(sum[i - 1], 0) + A[i];
		
		maxValue = max(maxValue, sum[i]);

		maxValue = max(maxValue, A[i]);
		
	}


	return maxValue;

}
