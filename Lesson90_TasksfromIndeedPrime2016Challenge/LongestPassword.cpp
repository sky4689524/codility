#include <locale>         // std::locale, std::isalnum

int solution(string &S) {
	
	// it has to contain only alphanumerical characters (a−z, A−Z, 0−9);
	// there should be an even number of letters; including 0
	// there should be an odd number of digits.
	bool check_alpha = true;
	int longest = -1;
	int alpha_count = 0;
	int num_count = 0;

	string word = "";
	for (auto x : S)
	{
		if (x != ' ')
		{
			word = word + x;

			if (!isalnum(x))
				check_alpha = false;

			if (isdigit(x))
				num_count++;

			if (isalpha(x))
				alpha_count++;

		}
		else{

			if (check_alpha) {
				
				if (((num_count % 2) == 1) && ((alpha_count % 2) == 0)) {


					if (longest < int(word.size()))
						longest = int(word.size());

				}



			}

			word = "";
			check_alpha = true;
			num_count = 0;
			alpha_count = 0;
		}

		
	}

	if (check_alpha) {

		if (((num_count % 2) == 1) && ((alpha_count % 2) == 0)) {


			if (longest < int(word.size()))
				longest = int(word.size());

		}

	}

	return longest;


}
