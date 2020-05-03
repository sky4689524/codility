// reference : https://codesays.com/2015/solution-to-polygon-concavity-index-by-codility/
// reference : https://www.crocus.co.kr/1288


// Check whether a given polygon in a 2D plane is convex; if not, return the index of a vertex that doesn't belong to the convex hull.
struct Point2D {

	int x;
	int y;

};

// https://algs4.cs.princeton.edu/91primitives/
// careful to overflow. 
int IsClockwise(Point2D A, Point2D B, Point2D C) {

	long temp1 = long(B.x - A.x) * long(C.y - A.y);
	long temp2 = long(C.x - A.x) * long(B.y - A.y);

	long result = temp1 - temp2;

	if (result > 0)
		return 1; // counter-clockwise

	else if (result < 0)
		return -1; // clockwise

	else
		return 0; // straight line 

}

int solution(vector<Point2D> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int N = A.size();

	// need to find the lowest point in y-axis
	int lowest_y = A[0].y;
	vector<int> lowest_index_y(1,0);

	lowest_index_y[0] = 0;

	for (int i = 1; i < N; i++) {

		if (A[i].y < lowest_y) {

			lowest_index_y.clear();

			lowest_y = A[i].y;
			lowest_index_y.push_back(i);
		}

		else if (A[i].y == lowest_y) {
			lowest_index_y.push_back(i);
		}
		
	}

	// Find a point which is not the lowest in y-axis
	// and immediately after a lowest-in-y-axis point
	int start_point = lowest_index_y[0];
	vector<bool>lowest_y_array(N, false);

	for (int i = 0; i < int(lowest_index_y.size()); i++) {

		lowest_y_array[lowest_index_y[i]] = true;
	}

	while (lowest_y_array[start_point] == true) {

		start_point = (start_point + 1) % N;
	}

	start_point = (start_point - 1 + N) % N;

	//reorganize the points so that, it is easier to check every three consecutive points in one loop
	vector<Point2D>::const_iterator starting_point = A.begin() + start_point;
	vector<Point2D>::const_iterator ending_point = A.end();
	vector<Point2D>rotate_A(starting_point, ending_point);

	vector<Point2D>::const_iterator Second_starting_point = A.begin();
	vector<Point2D>::const_iterator Second_ending_point = A.begin() + start_point;

	// rotate_A = A[start_point : ] + A[:start_point]
	rotate_A.insert(rotate_A.end(), Second_starting_point, Second_ending_point);

	// find the start point, the direction is non-zero
	int direction = IsClockwise(rotate_A[int(rotate_A.size()) - 1], rotate_A[0], rotate_A[1]);
	vector<Point2D> extended_A(rotate_A.begin(), rotate_A.end());

	vector<Point2D>::const_iterator Third_starting_point = rotate_A.begin();
	vector<Point2D>::const_iterator Third_ending_point = rotate_A.begin() + 2;

	//extended_A = rotate_A + rotated_A[:2]
	extended_A.insert(extended_A.end(), Third_starting_point, Third_ending_point);

	for (int i = 0; i < N; i++) {

		int temp = IsClockwise(extended_A[i], extended_A[i + 1], extended_A[i + 2]);
		if (temp * direction < 0)
			// compute the original index and return
			return (i + 1 + start_point) % N;
	}

	// if every point is on the convex hull
	return -1;
}
