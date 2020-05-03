#include <iostream>
#include <memory>
#include <vector>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {

	vector<int> minimal_factors(P.size(), 0);

	vector<int> pre_sum_A;
	vector<int> pre_sum_C;
	vector<int> pre_sum_G;

	int count_A = 0;
	int count_C = 0;
	int count_G = 0;

	int A = 0, C = 0, G = 0;

	// prepare 
	for (int i = 0; i < S.size(); i++) {

		if (S[i] == 'A')
			count_A++;
		else if (S[i] == 'C')
			count_C++;
		else if (S[i] == 'G')
			count_G++;

		pre_sum_A.push_back(count_A);
		pre_sum_C.push_back(count_C);
		pre_sum_G.push_back(count_G);


	}

	// calculate minimal factors
	for (int i = 0; i < Q.size(); i++) {

		A = (S[P[i]] == 'A') ? 1 : 0;
		C = (S[P[i]] == 'C') ? 1 : 0;
		G = (S[P[i]] == 'G') ? 1 : 0;

		if (pre_sum_A[Q[i]] - pre_sum_A[P[i]] + A > 0)
			minimal_factors[i] = 1;
		else if (pre_sum_C[Q[i]] - pre_sum_C[P[i]] + C > 0)
			minimal_factors[i] = 2;
		else if (pre_sum_G[Q[i]] - pre_sum_G[P[i]] + G > 0)
			minimal_factors[i] = 3;
		else
			minimal_factors[i] = 4;
	
	}

	return minimal_factors;
}

