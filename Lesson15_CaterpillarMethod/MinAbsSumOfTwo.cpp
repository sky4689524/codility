int solution(vector<int> &A) {

	int front = 0;
	int end = 0;
	int N = A.size();
	int temp = 0;
	int min = 0;

	sort(A.begin(), A.end()); // ascending order 

	if (A[0] >= 0)
		return abs(A[0] + A[0]); // All positive

	if (A[N - 1] <= 0)
		return abs(A[N - 1] + A[N - 1]); // All negative

	front = 0;
	end = N - 1;

	min = abs(A[N - 1] + A[N - 1]);


	while (front <= end) {

		temp = abs(A[front] + A[end]);

		if (temp < min)
			min = temp;

		if (front == end)
			break;

		else if (abs(A[front + 1] + A[end]) <= temp)
			front++;

		else if (abs(A[front] + A[end - 1]) <= temp)
			end--;

		else {
			front++;
			end--;
		}

	}

	return min;

}
