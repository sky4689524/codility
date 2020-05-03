// reference : https://codesays.com/2014/solution-to-array-inversion-count-by-codility/

// use merge sort algorithm but modified 
int MergeSort(vector<int> &A, int first, int last) {

	int mid = (first + last) / 2;
	int left_inv = 0, right_inv = 0;

	if (first < last) {

		left_inv = MergeSort(A, first, mid);

		if (left_inv == -1)
			return -1;

		right_inv = MergeSort(A, mid + 1, last);

		if (right_inv == -1)
			return -1;

	}

	else
		return 0;

	int first_index = first; // the index of first part
	int second_index = mid + 1; // the index of second part

	vector<int> temp((last - first) + 1, 0); // the sorted result vector
	int temp_index = 0;
	int merge_inv = 0; // the number of merging inverse

	while (first_index <= mid && second_index <= last) {

		if (A[first_index] <= A[second_index]){
			temp[temp_index] = A[first_index];
			first_index++;

		}

		// the elements of second part should be greater than the elements of first part
		//  so need to be inversed. 
		else {

			temp[temp_index] = A[second_index];
			second_index++;
			merge_inv += mid - first_index + 1;
			if (merge_inv > 1000000000)
				return -1;
		}

		temp_index++;
	}

	// process the leftover in firstpart
	if (first_index != mid + 1) {

		while (first_index <= mid) {
			temp[temp_index] = A[first_index];
			first_index++;
			temp_index++;
		}
	}

	// the process of the leftover in second part
	if (second_index != last + 1) {

		while (second_index <= last) {
			temp[temp_index] = A[second_index];
			second_index += 1;
			temp_index++;
		}
	}

	// assign the sorted version to original vector
	for (int i = 0; i < (last - first) + 1; i++) {

		A[i + first] = temp[i];

	}

	if (merge_inv + left_inv + right_inv > 1000000000)
		return -1;

	else
		return merge_inv + left_inv + right_inv;
}

// Compute number of inversion in an array.
int solution(vector<int> &A) {

	int N = A.size();

	return MergeSort(A, 0, N - 1);

}
