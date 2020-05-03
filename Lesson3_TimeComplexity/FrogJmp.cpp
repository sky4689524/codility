int solution(int X, int Y, int D) {

	int distance = Y - X;
	int count_jumps = 0;

	count_jumps = distance / D;

	if (distance % D > 0)
		count_jumps++;

	return count_jumps;

}
