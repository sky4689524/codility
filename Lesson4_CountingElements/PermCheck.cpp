int solution(vector<int> &A) {

	int pernumber = 1;

	sort(A.begin(), A.end());

	for (int i = 0; i < A.size(); i++) {

		if (A[i] == pernumber)
			pernumber++;
		else
			return 0;
	}


	return 1;
}
