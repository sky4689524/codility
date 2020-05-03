// reference : https://codesays.com/2016/solution-to-slalom-skiing-by-codility/

#include <locale>         // std::locale, std::isalnum


// The original longest increasing sequences. 
// https://en.wikipedia.org/wiki/Longest_increasing_subsequence
int FindLongestSequence(vector<long> &s) {

	// The length of the longest increasing subsqeuence. 
	int sequences = 0;
	int N = s.size();

	// smallest_value[i] = j means, for all i-length increasing subseqence
	// the minimum value of their laste elements is j.
	vector<long> smallest_value(N + 1, 1000000001);

	smallest_value[0] = -1; 

	for (int i = 0; i < N; i++) {

		int lower = 0;
		int upper = sequences;

		// binary search
		while (lower <= upper) {

			int mid = floor(double(upper + lower) / 2);

			//cout << "mid : " << mid << endl;

			if (s[i] < smallest_value[mid])
				upper = mid - 1;

			else if (s[i] > smallest_value[mid])
				lower = mid + 1;

		}

		// the result "lower" is the index j.
		if (smallest_value[lower] == 1000000001) {
			smallest_value[lower] = s[i];
			sequences += 1;
		}

		else{

			//cout << "lower : " << lower << endl;

			smallest_value[lower] = min(smallest_value[lower], s[i]);
			
		}
	}


	return sequences;

}


int solution(vector<int> &A) {

	int maximum_bound = 0;
	int N = A.size();
	vector<long> multi_universe;

	maximum_bound = 1000000000 + 1;

	for (int i = 0; i < N; i++) {

		// third universe of sequence
		multi_universe.push_back(maximum_bound * 2 + A[i]);

		// second universe of sequence
		multi_universe.push_back(maximum_bound * 2 - A[i]);

		// first universe of sequence
		multi_universe.push_back(A[i]);

	}


	return FindLongestSequence(multi_universe);
}
