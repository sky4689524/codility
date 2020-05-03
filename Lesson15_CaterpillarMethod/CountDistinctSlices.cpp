// reference : https://sites.google.com/site/spaceofjameschen/home/codibility/15-2-counttriangles

int solution(int M, vector<int> &A) {

	int total_slices = 0;
	int N = A.size();
	vector<bool> seen(M + 1, false);

	int start = 0, end = 0;

	// key point: move the "start" and "end" of a slice
	while (start < N && end < N) {


		// case 1 : distinct (end)
		if (seen[A[end]] == false) {

			total_slices += (end - start + 1);

			if (total_slices >= 1000000000)
				return 1000000000;

			// increase hte slice to right by "1"
			seen[A[end]] = true;
			end++;
		}

	
		// case 2 : not distinct

		else {

			// decrease the slice from left by "1"
			// remove A[start] from "seen"
			seen[A[start]] = false;
			start++;

		}

	}



	return min(total_slices, 1000000000);

}
