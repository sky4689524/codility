int solution(int X, vector<int> &A) {

	set<int> s;

	for (int i = 0; i < A.size(); i++) {

		s.insert(A[i]);

		if (s.size() == X)
			return i;
	}

	return -1;
}
