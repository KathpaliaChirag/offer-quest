#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int solve(int n, vector<int>& proj) {
	// max pq
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) pq.push(proj[i]);

	int res = 0;
	int to_push = -1;
	while (!pq.empty()) {
		int x = pq.top(); pq.pop();
		x--;
		if (to_push > 0) pq.push(to_push);
		to_push = x;
		res++;
	}

	return res;
}


int main(int argc, char const *argv[]) {
	vector<int> proj1 = {7, 2, 3};	// expected: 11
	vector<int> proj2 = {5}; // expected 1
	vector<int> proj3 = {7,6,5,4,3,2,1};	// expected 28
	vector<int> proj4 = {3, 3}; 	// expected 6

	cout << solve(proj3.size(), proj3) << '\n'; 

	return 0;
}