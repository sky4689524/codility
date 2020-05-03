// reference : https://massivealgorithms.blogspot.com/2016/12/flood-depth-codility.html

int solution(vector<int> &A) {

	int N = A.size();
	int maximul_depth = 0;
	int maxIdx = 0, lowIdx = 0;
	int max_height = 0;
	int low_height = 0;

	if (N < 3)
		return 0;

	for (int i = 1; i < N; i++) {

		max_height = A[maxIdx];
		low_height = A[lowIdx];

		if (A[i] > max_height)
		{
			maximul_depth = max(max_height - low_height, maximul_depth);
			maxIdx = i;
			lowIdx = i;
		}
		else if (A[i] > low_height)
			maximul_depth = max(A[i] - low_height, maximul_depth);

		else if (A[i] < low_height)
			lowIdx = i;


	}


	return maximul_depth;


}
