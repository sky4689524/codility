// reference : http://codility-lessons.blogspot.com/2015/03/lesson-10-chocolatesbynumbers.html

// find the least common multiple of N and M(LCM)
// LCM can be comupted by (N * M) / gcd(N,M). LCM / M = (N * M) / gcd(N,M) / M = N / gcd(N, M)

int gcd(int a, int b, int res)
{
	if (a == b) {
		return res * a;
	}

	else if (a % 2 == 0 && b % 2 == 0) {
		return gcd(a >> 1, b >> 1, 2 * res);
	}

	else if (a % 2 == 0) {
		return gcd(a >> 1, b, res);
	}

	else if (b % 2 == 0) {
		return gcd(a, b >> 1, res);
	}

	else if (a > b) {
		return gcd(a - b, b, res);
	}

	else // b >= a
		return gcd(a, b - a, res);
}

int solution(int N, int M)
{

	return (N / gcd(N, M, 1));
}
