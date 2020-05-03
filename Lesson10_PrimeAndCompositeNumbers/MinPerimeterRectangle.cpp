int solution(int N) {

	int minimum = -1;
	long temp = 0;

	for (int i = 1; i <= sqrt(N); i++) {

		if (N % i == 0) {

			if (N / i == i){

				temp = 2 * (i + i);
			}

			else{

				temp = 2 * (i + int(N / i));
			}
		}

		if (minimum == -1)
			minimum = temp;

		if (minimum > temp)
			minimum = temp;


	}

	return minimum;
	
}

