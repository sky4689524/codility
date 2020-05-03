// reference : https://massivealgorithms.blogspot.com/2015/07/solution-to-common-prime-divisors-by.html

// compute the greatest common divisor
int gcd(int x, int y) {

	if (x % y == 0)
		return y;

	else
		return gcd(y, x % y);

}

bool CheckSamePrimeDivisor(int x, int y) {

	int g = 0;
	int x_g = 0;
	int y_g = 0;

	g = gcd(x, y); // the common prime divisors

	while (x != 1) {

		x_g = gcd(x, g);

		if (x_g == 1) // x does not contain anymore
			break;

		x /= x_g;
	}

	// If x and y have exactly the same common prime divisors, x must be composed by
	// the prime divisors in g. So after preivous loop, x must be one.
	if (x != 1) 
		return false;

	while (y != 1) {
		y_g = gcd(y, g);

		if (y_g == 1)
			break;

		y /= y_g;
	}

	return y == 1;


}


int solution(vector<int> &A, vector<int> &B)
{
	int count = 0;
	int small = 0;
	int big = 0;

	for (int i = 0; i < A.size(); i++) {

		if (A[i] <= B[i])
		{
			small = A[i];
			big = B[i];
		}
		else {

			small = B[i];
			big = A[i];
		}
		
		if (CheckSamePrimeDivisor(big, small) == true)
			count++;
	}

	return count;

}
