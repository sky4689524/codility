int solution(vector<int> &A) {

	int unpair = A.at(0);
	int maximum_size = A.size();

	for (int i = 1; i < maximum_size; i++) {

		unpair = unpair ^ A.at(i);
	}

	return unpair;

}
