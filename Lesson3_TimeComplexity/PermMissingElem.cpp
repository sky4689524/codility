int solution(vector<int> &A) {

	long size = A.size();
	long sum_of_elems = 0;
	long total_sum = 0;
	long missing_element = 0;

	sum_of_elems = std::accumulate(A.begin(), A.end(), 0);

	total_sum = ((size + 1) * (size + 2) ) / 2;

	missing_element = total_sum - sum_of_elems;

	return missing_element;

}
