int solution(vector<int> &A) {

	int max_blocks = 0;
	int N = A.size();
	vector<int> peak_position;
	vector<int> block_numbers;
	int peak_size = 0;
	int block_size = 0;

	// when the number of arrays is less than 3, just return 0
	if (N < 3)
		return 0;

	for(int i = 1; i < N - 1; i++) {

		if (A[i - 1] < A[i] && A[i] > A[i + 1])
			peak_position.push_back(i);

	}

	peak_size = peak_position.size();

	// when the number of peaks is less than 2, then just return the size of peaks.
	if (peak_size < 2)
		return peak_size;

	for (int i = 1; i <= sqrt(N); i++) {

		if (N % i == 0) {

			if (N / i == i){
			
				if(peak_size >= i)
					block_numbers.push_back(i);

			}

			else {

				if(peak_size >=i)
					block_numbers.push_back(i);

				if(peak_size >= int(N / i))
					block_numbers.push_back(int(N / i));
			}

		}
	}

	sort(block_numbers.begin(), block_numbers.end());

	max_blocks = 1;

	for (int i = 1; i < block_numbers.size(); i++) {

		block_size = N / block_numbers[i];
		int count = 0;
		int peak_pos = 0;
		bool inside_block = false;
		
		for (int index = 1; index <= block_numbers[i];) {

			if ((peak_position[peak_pos] < index * block_size) && (peak_position[peak_pos] >= (index - 1) * block_size)){
				peak_pos++;
				inside_block = true;
				
			}

			else{


				if (inside_block == true)
					count++;

				index++;
				inside_block = false;
				
			}

			if (peak_pos >= peak_size){
			
				if (inside_block == true)
					count++;

				
				break;

			}

		}

		if(count == block_numbers[i])
			max_blocks = block_numbers[i];

	}


	return max_blocks;
	
}
