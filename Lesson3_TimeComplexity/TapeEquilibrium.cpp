#include <algorithm>

int solution(vector<int> &A) {

	vector<int> pre_sum;
	int sum = 0;
	int minimum_diff = numeric_limits<int>::max();
	int abs_diff = 0;

	for (auto n : A) {
		sum += n;
		pre_sum.push_back(sum);
	}

	for (int P = 1; P < pre_sum.size(); P++) {
		abs_diff = abs(pre_sum[P - 1] * 2 - pre_sum[pre_sum.size() - 1]);

		minimum_diff = min(minimum_diff, abs_diff);
	}


	return minimum_diff;
}
