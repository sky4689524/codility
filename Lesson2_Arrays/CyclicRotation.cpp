vector<int> solution(vector<int> &A, int K) {

	int i = 0, n = 0;
	int temp = 0;
	vector<int> vector_temp(A);

	if (vector_temp.size() > 0) {
		for (n = 0; n < K; n++) {

			temp = vector_temp.at(vector_temp.size() - 1);

			for (i = vector_temp.size() - 1; i > 0; i--) {
				vector_temp.at(i) = vector_temp.at(i - 1);
			}

			vector_temp.at(0) = temp;
		}
		
	}

	for (int x : vector_temp)
		cout << x << " ";

	return vector_temp;
}
