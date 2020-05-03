// reference : https://codesays.com/2014/solution-to-fish-by-codility/

int solution(vector<int> &A, vector<int> &B) {

	int N = A.size();
	int alive_count = 0; // the number of fish that will stay alive
	vector <int> downstream; // the record  the fish flowing downstream
	int down_count = 0; // the record the number of elements in downstream


	for (int i = 0; i < N; i++) {

		// compute for each fish
		if (B[i] == 1) {

			// This fish is flowing downstream. I would never meet the previous fishs. 
			// But possibly it has to fight with the downstream fishs.
			downstream.push_back(A[i]);
			down_count++;


		}

		// This fish is flowing upstream.
		// It would either eat all the previous downstream-flow fish, and stay alive.
		// OR be eaten by one of the previous downsteam-flow fish, wihch is bigger and died.
		else {

			// It has to fight with each preivous living fish, with nearest fish
			while (down_count != 0) {

				if (downstream[downstream.size() - 1] < A[i]) {

					// win and to continue the next fight
					down_count--;
					downstream.pop_back();


				}
				else
					// lose and die
					break;

			}

			// this upstream-flow fish eats all the previous downstream-flow fishes Win and stay alive.
			if(down_count == 0)
				alive_count += 1;
		}

	}

	// currently, all the downstream flow fish in stack downstream will not meet with any fish.
	// They will stay alive.
	alive_count += downstream.size();

	return alive_count;
}
