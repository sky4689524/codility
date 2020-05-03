int solution(vector<int> &A) {

	int N = A.size();
	int dominating_number = 0;
	int dominate_element = 0;

	map<int, int> stack;

	for (int i = 0; i < N; i++) {

		if (stack.count(A[i]) == 0)
			stack[A[i]] = 1;

		else
			stack[A[i]]++;

	}

	for (auto const& pair : stack)
	{
		if (dominating_number < pair.second) {
			dominating_number = pair.second;
			dominate_element = pair.first;
		}
	
	}

	if (dominating_number > N / 2){

		for (int i = 0; i < N; i++) {
			if (dominate_element == A[i])
				return i;
		}
	}

	
	return -1;
}
