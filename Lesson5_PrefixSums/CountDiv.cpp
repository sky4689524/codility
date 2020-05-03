// reference : https://www.geeksforgeeks.org/count-numbers-divisible-m-given-range/

int solution(int A, int B, int K) {

	// Add 1 explicitly as A is divisible by K
	if (A % K == 0)
		return (B / K) - (A / K) + 1;

	return (B / K) - (A / K);
}

int main()
{

	cout << solution(20, 70, 10) << endl;

	system("pause");

	return 0;
}

