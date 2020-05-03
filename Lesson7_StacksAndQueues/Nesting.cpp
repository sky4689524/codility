int solution(string &S) {

	int N = S.size();
	char s = 0;

	// (
	// )
	vector <char> temp;

	for (int i = 0; i < N; i++) {

		s = S[i];

		if (s == ')') {

			if (temp.size() == 0)
				return 0;
		}


		if (s == '(') {
			temp.push_back(s);

		}

		else if (s == ')') {

			if (temp[temp.size() - 1] != '(')
				return 0;

			temp.pop_back();
		}
	}

	if (temp.size() == 0)
		return 1;
	else
		return 0;
}
