// refernece : https://rafal.io/posts/codility-max-profit.html

int solution(vector<int> &A) {

	int N = A.size();
	int maxSofar = 0;
	int maxEarning = 0;
	int minPrice = 0;

	if (N == 0 || N == 1)
		return 0;

	minPrice = A[0];

	for (int i = 1; i < N; i++) {

		maxEarning = max(0, A[i] - minPrice);
		minPrice = min(minPrice, A[i]);
		maxSofar = max(maxSofar, maxEarning);
	}

	return maxSofar;

}
