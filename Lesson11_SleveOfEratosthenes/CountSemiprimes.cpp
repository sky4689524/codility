int checkSemiprime(int num) {

	int count = 0;

	for (int i = 2; count < 2 && i * i <= num; i++) {

		while (num % i == 0) {
			num /= i;
			count++;
		}

	}

	// If the number is greater than 1, add it to the count variable as it indicates the number remain is prime number
	if (num > 1)
		count++;

	return count == 2;

	
}


vector<int> solution(int N, vector<int> &P, vector<int> &Q) {

	int M = P.size();
	int count = 0;
	int temp = 0;
	vector<int> each_prime(N + 1, 0);
	vector<int> answer(M, 0);

	for (int i = 1; i < each_prime.size(); i++) {

		if (checkSemiprime(i) == 1)
			temp++;

		each_prime[i] += temp;
		
	}

	for (int i = 0; i < M; i++) {

		int left = P[i];
		int right = Q[i];

		temp = each_prime[right] - each_prime[left - 1];

		answer[i] = temp;

	}

	for (int i = 0; i < M; i++)
		cout << answer[i] << endl;

	return answer;

}
