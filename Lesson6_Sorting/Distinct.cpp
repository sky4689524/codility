
int solution(vector<int> &A) {
	
	set<int> s;

	for (int i = 0; i < A.size(); i++) {
		s.insert(A[i]);
	}

	return int(s.size());

}
