int solution(int N) {

	int largestGap = 0;
	int tempGap = 0;
	int i = 0;
	int n = N;
	int temp = 0;
	int count = 0;
	char start_flag = false;

	// change number to binary
	// find binary gap. 
	for (i = 0; n > 0; i++) {

		temp = n % 2;
		
		//cout << "temp : " << temp << endl;
		//cout << "count : " << count << endl;

		if (temp == 1) {

			if (start_flag == false){
				start_flag = true;
				count = 0;
			}

			else{

				if (count > 0)
					tempGap = count - 1;
				else
					tempGap = count;

				if (tempGap > largestGap)
					largestGap = tempGap;

				count = 0;

			}
		}

		n = n / 2;
		count++;
		

	}

	// return the lenght of its longest binary gap.
	return largestGap;
}
