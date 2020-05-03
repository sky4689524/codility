int solution(vector<int> &A) {

	int temp = 0;
	int start = 0;
	int min_start = start;
	double minAvg = 0.0;
	double temp_avg = 0.0;
	vector<int> accumulate(A.size());

	for (int i = 0; i < A.size(); i++)
	{
		temp += A[i];

		accumulate[i] = temp;

	}

	minAvg = double(accumulate[1] - accumulate[start] + A[start]) / (1 - start + 1);
	for (int i = 1; i < A.size(); i++) {

		temp_avg = double(accumulate[i] - accumulate[start] + A[start]) / (i - start + 1);

		if (temp_avg < minAvg) {
			minAvg = temp_avg;
			min_start = start;
		}
		if (A[i] < minAvg)
			start = i;
	}


	return min_start;
}
