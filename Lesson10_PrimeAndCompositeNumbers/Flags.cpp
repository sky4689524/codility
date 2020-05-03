// reference : https://stackoverflow.com/questions/19466115/peak-and-flag-codility-latest-chellange

int solution(vector<int> &A) {

	int N = A.size();
	int max_flag = 0;
	int left = 0, right = 0, need = 0;
	int distance = 0;
	vector<int> peak;
	vector<int> peak_distance;

	if (N < 3)
		return 0;

	for (int i = 1; i < N - 1; i++) {

		if ((A[i - 1] < A[i]) && (A[i] > A[i + 1])) {
			peak.push_back(i);
			//cout << i << endl;

		}

	}

	if (peak.size() < 2)
		return int(peak.size());

	max_flag = min(int(ceil(sqrt(N))), int(peak.size())); // initialize the max number of flags
	distance = max_flag; // required distance between flags


						 // try to set max number of flags then 1 less, etc(2 flags are already set)
	for (int k = max_flag - 2; k > 0; k--) {

		left = peak[0];
		right = peak[peak.size() - 1];
		need = k; // how many more flags we need to set

		for (int i = 1; i <= int(peak.size()) - 2; i++) {

			// found one more flag for distance
			if (peak[i] - left >= distance && right - peak[i] >= distance) {

				if (need == 1)
					return (k + 2);

				need--;
				left = peak[i];
			}

			if (right - peak[i] <= need * (distance + 1))
				break; // impossible to set need more flags for distance
		}

		if (need == 0)
			return k + 2;

		distance--;
	}

	return 2;
}
