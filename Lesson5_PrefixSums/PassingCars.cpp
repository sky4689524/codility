int solution(vector<int> &A) {

	int pairs = 0;
	int end = A.size();
	int temp = 0;
	vector<int> location;
	vector<int> pre_s(end);

	for (int i = 0; i < end; i++) {

		if (A[i] == 0)
			location.push_back(i);

		temp += A[i];
		pre_s[i] = temp;


	}
	for (int i = 0; i < location.size(); i++) {

		pairs += (pre_s[end - 1] - pre_s[location[i]]);

		if (pairs > 1000000000)
			return -1;
	}


	return pairs;

}
