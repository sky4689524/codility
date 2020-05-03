int solution(vector<int> &A) {

	int N = A.size();
	set<int> s;

	for (int i = 0; i < N; i++) {

		s.insert(abs(A[i]));

	}
	

	return int(s.size());

}
