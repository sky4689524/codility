int solution(vector<int> &A) {

	int positive_number = 1;

	sort(A.begin(), A.end());

	for (int i = 0; i < A.size(); i++) {

		if (A[i] < 0)
			continue;

		else {

			if (A[i] == positive_number)
				positive_number++;
			else if (A[i] > positive_number)
				return positive_number;
		}

	}


	return positive_number;
}

