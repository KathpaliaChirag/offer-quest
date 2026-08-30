#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
	int n;
	vector<int> parent;

	DSU(int tn) {
		n = tn;
		parent = vector<int>(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find_set(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find_set(parent[x]);
	}

	void merge(int x, int y) {
		x = find_set(x);
		y = find_set(y);
		parent[x] = y;
	}
};


// Runtime: O(friends_nodes * friends_nodes * num_companies)
int solve(int friends_nodes, int num_companies, vector<vector<int>>& edges) {
	vector<DSU> dsu(num_companies, DSU(friends_nodes));

	for (auto& v: edges) 
		dsu[v[2] - 1].merge(v[0] - 1, v[1] - 1);

	vector<vector<int>> common(friends_nodes, vector<int>(friends_nodes, 0));
	for (int i = 0; i < friends_nodes; i++) {
		for (int j = i + 1; j < friends_nodes; j++) {
			for (int k = 0; k < num_companies; k++) {
				if (dsu[k].find_set(i) == dsu[k].find_set(j))
					common[i][j]++;
			}		
		}
	}

	int res = 0;
	int curmax = 0;
	for (int i = 0; i < friends_nodes; i++) {
		for (int j = i + 1; j < friends_nodes; j++) {
			if (common[i][j] >= curmax) {
				curmax = common[i][j];
				res = (i+1) * (j+1);
			}	
		}
	}

	return res;
}


int main(int argc, char const *argv[]) {
	int friends_nodes = 4;
	int num_companies = 4;
	vector<vector<int>> edges = { {1, 2, 1}, {2, 4, 1}, {1, 2, 2}, {2, 4, 2}, {3, 4, 2}, {1, 2, 3}, {1, 3, 3}, {1, 2, 4}, {3, 4, 4} };
	cout << solve(friends_nodes, num_companies, edges) << '\n';

	return 0;
}