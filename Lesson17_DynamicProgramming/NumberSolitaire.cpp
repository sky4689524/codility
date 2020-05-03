// reference : https://github.com/Mickey0521/Codility/blob/master/NumberSolitaire.java

int solution(vector<int> &A) {

	int N = A.size();
	int MAX_DICE = 6;
	int MINVALUE = -2147483646;

	vector<int> sub_solutions(N, MINVALUE);

	sub_solutions[0] = A[0];

	for (int i = 1; i < N; i++) {

		int max_pre = MINVALUE;

		for (int die = 1; die <= MAX_DICE; die++) {

			if (i - die >= 0)
				max_pre = max(max_pre, sub_solutions[i - die] + A[i]);

		}

		sub_solutions[i] = max_pre;

	}

	return sub_solutions[N - 1];

}
