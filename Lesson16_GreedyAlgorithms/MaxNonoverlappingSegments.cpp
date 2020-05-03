int solution(vector<int> &A, vector<int> &B) {

	int segments = 1;
	int N = A.size();
	vector<int> left_stack;
	vector<int> right_stack;

	if (N < 2)
		return N;

	left_stack.push_back(A[0]);
	right_stack.push_back(B[0]);

	for (int i = 1; i < N; i++) {

		int R = right_stack.size();
		int L = left_stack.size();

		if (left_stack[L - 1] <= A[i] && B[i] < right_stack[R - 1]) {
			
			left_stack.pop_back();
			left_stack.push_back(A[i]);

			right_stack.pop_back();
			right_stack.push_back(B[i]);
		}

		else if (right_stack[R - 1] < A[i]) {

			segments++;

			left_stack.push_back(A[i]);
			right_stack.push_back(B[i]);

		}


	}


	return segments;


}
