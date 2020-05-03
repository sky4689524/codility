// reference : https://www.martinkysel.com/codility-stonewall-solution/

int solution(vector<int> &H) {

	int N = H.size();
	int blocks = 0;

	vector <int> block_stacks;

	for (int i = 0; i < N; i++) {

		// remove all blocks in stack that are bigger than the current height
		while (block_stacks.size() != 0 && block_stacks[block_stacks.size() - 1] > H[i])
			block_stacks.pop_back();

		// when the height is the same, we just pass
		if (block_stacks.size() != 0 && block_stacks[block_stacks.size() - 1] == H[i])
			continue;

		// when the height in stack is lower than current height, push into the stack
		else {
			blocks++;
			block_stacks.push_back(H[i]);
		}
	}

	return blocks;

}
