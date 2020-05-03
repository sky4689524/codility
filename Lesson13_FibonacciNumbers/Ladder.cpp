// reference : https://codesays.com/2014/solution-to-ladder-by-codility/

int Fib(int M) {

	if (M == 0)
		return 0;

	else if (M == 1)
		return 1;

	else
		return Fib(M - 1) + Fib(M - 2);

}

vector<int> solution(vector<int> &A, vector<int> &B)
{
	int L = A.size();

	vector<int> modules(L,0);
	vector<int> rungs(L, 0);
	vector<int> fibs;

	// pre-compute module 2^B[i]
	for (int i = 0; i < L; i++)
		modules[i] = (1 << B[i]) - 1;
	
	// compute the fibonacci numbers 
	fibs.push_back(0);
	fibs.push_back(1);

	for (int i = 2; i < L + 2; i++)
		fibs.push_back(fibs[i - 1] + fibs[i - 2]);

	// To climb to A[i] rungs, you could either come from A[i] - 1 with an 1 or A[i] -2 with 2 steps.
	// Therefore, the number of different ways of climbing to the top of the ladder is the Fibonacci number at A[i] + 1
	for (int i = 0; i < L; i++) {

		rungs[i] = fibs[A[i] + 1] & modules[i];

		//cout << rungs[i] << endl;
	}


	return rungs;


}
