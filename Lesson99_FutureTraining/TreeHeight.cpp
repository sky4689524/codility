struct tree {

	int x;
	tree *l;
	tree *r;

};

int treeHeight(tree *T) {

	if (T == NULL)
		return 0;

	else {

		int left_height = treeHeight(T->l);
		int right_height = treeHeight(T->r);

		if (left_height >= right_height)
			return left_height + 1;

		else
			return right_height + 1;

	}


}

int solution(tree * T) {
	// write your code in C++14 (g++ 6.2.0)

	int height = treeHeight(T);

	return height - 1;
}
