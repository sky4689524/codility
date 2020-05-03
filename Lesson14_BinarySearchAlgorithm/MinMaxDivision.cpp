// refernece : http://codility-lessons.blogspot.com/2015/03/lesson-12-minmaxdivision-min-max.html

bool CompareNumber(int mid, int K, vector<int> &A) {

	int sum = 0;
	int N = A.size();

	for (int i = 0; i < N; i++) {

		sum += A[i];

		if (sum > mid) {
			sum = A[i];
			K--;
		}
		if (K <= 0) {
			return false;
		}
	}

	return true;

}

int solution(int K, int M, vector<int> &A) {
	
	int N = A.size();
	int sum = 0;
	int max = 0;
	int low = 0, high = 0;
	int minimum = 0;

	max = A[0];

	for (int i = 0; i < N; i++) {

		max = max < A[i] ? A[i] : max;

		sum += A[i];
	}


	low = max;
	high = sum;

	minimum = sum;

	while (low <= high) {

		int mid = (low + high) / 2;

		if (CompareNumber(mid, K, A)) {

			minimum = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}

	}


	return minimum;


}
