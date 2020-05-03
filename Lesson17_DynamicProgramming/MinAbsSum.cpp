// reference : https://codility.com/media/train/solution-min-abs-sum.pdf

// find the lowest absolute sum of elements
int solution(vector<int> &A) {

	int max = 0, sum = 0;
	int N = A.size();
	int minimum = 0;

	for (int i = 0; i < N; i++) {
		
		A[i] = abs(A[i]);

		max = (max <= A[i]) ? A[i] : max;
		sum += A[i];
	}

	vector<int> count(max + 1, 0);

	for (int i = 0; i < N; i++) {
		count[A[i]] += 1;
	}


	// dp[i] == -1 no sum, dp[i] == 0 sum.
	vector<int> dp(sum + 1, -1);
	
	dp[0] = 0;

	for (int i = 1; i <= max; i++) {

		if (count[i] <= 0)
			continue;
		
		for (int j = 0; j <= sum; j++) {

			if (dp[j] >= 0)
				dp[j] = count[i];

			else if (j >= i && dp[j - i] > 0)
				dp[j] = dp[j - i] - 1;
		}

	}


	minimum = sum;

	for (int i = 0; i * 2 <= sum; i++) {

		if (dp[i] >= 0) {
			
			int diff = sum - 2 * i;

			minimum = (diff < minimum) ? diff : minimum;

		}

	}


	return minimum;
}
