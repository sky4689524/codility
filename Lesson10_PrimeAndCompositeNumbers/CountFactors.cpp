int solution(int N) {

	int count = 0;

	for (int i = 1; i <= sqrt(N); i++) {

		if (N % i == 0) {

			if (N / i == i)
				count++;

			else
				count = count + 2;

		}
	}


	return count;

}
