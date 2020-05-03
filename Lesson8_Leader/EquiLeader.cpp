int solution(vector<int> &A) {

	int N = A.size();
	int dominating_number = 0;
	int dominate_element = 0;
	int temp = 0;
	int equi_count = 0;

	map<int, int> stack;
	vector<int> count(N);

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

			count[i] += temp;

			if (A[i] == dominate_element) {
				
				temp++;

				count[i] = temp;
			}
		}

		for (int i = 0; i < N; i++) {

			temp = dominating_number - count[i];

			if ((count[i] > (i + 1) / 2) && (temp > (N - i - 1) / 2))
				equi_count++;
		}
	}

	
	return equi_count;
}
