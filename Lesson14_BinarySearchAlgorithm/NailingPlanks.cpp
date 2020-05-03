// reference : https://codesays.com/2014/solution-to-nailing-planks-by-codility/

bool CheckNail(vector<int> &A, vector<int> &B, vector<int> &C, int higher) {

	int N = A.size();
	int M = C.size();
	int temp = 0;

	vector<int> count_C(M * 2 + 1, 0);

	for (int i = 0; i < higher; i++) {
		count_C[C[i]] = 1;
	}

	for (int i = 0; i < count_C.size(); i++) {

		temp += count_C[i];
		count_C[i] = temp;
	}

	for (int i = 0; i < N; i++) {
		if (count_C[A[i] - 1] == count_C[B[i]])
			return false;
	}

	return true;
}


int solution(vector<int> &A, vector<int> &B, vector<int> &C) {


	int low = 1;
	int high = C.size();

	if (!CheckNail(A, B, C, high))
		return -1;

	while (low < high) {

		int nail = (low + high) / 2;

		if (CheckNail(A, B, C, nail))
			high = nail;

		else
			low = nail + 1;


	}


	return low;

}
