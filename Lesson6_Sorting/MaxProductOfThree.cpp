int solution(vector<int> &A) {
	
	int max_product = 0;
	int max_product2 = 0;
	int max_size = A.size();

	sort(A.begin(), A.end());

	max_product = A[max_size - 3] * A[max_size - 2] * A[max_size - 1];

	if ((A[max_size - 1] < 0) || (A[0] > 0))
		return max_product;

	max_product2 = A[0] * A[1] * A[max_size - 1];

	return max(max_product, max_product2);

}

