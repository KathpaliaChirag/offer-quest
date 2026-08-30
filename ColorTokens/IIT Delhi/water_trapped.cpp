#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, -1,1 };


void bfs(vector<string>& v, int i, int j) {
	if (v[i][j] != '.') return;
	v[i][j] = '*';
	int n = v.size(), m = v[0].size();

	queue< pair<int, int> > q;
	q.push({i, j});

	while (!q.empty()) {
		auto p = q.front(); q.pop();
		int x = p.first, y = p.second;

		for (int k = 0; k < 4; k++) {
			int ii = x + dirx[k], jj = y + diry[k];
			if (ii < 0 || jj < 0 || ii >= n || jj >= m || v[ii][jj] != '.') continue;
			v[ii][jj] = '*';
			q.push({ii, jj});
		}
	}
}


int solve(vector<string>& v) {
	int n = v.size(), m = v[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0 || i == n-1 || j == m-1) bfs(v, i, j);
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '.') res++;
		}
	}

	// for (auto& x: v) {
	// 	cout << x << endl;
	// }

	return res;
}



int main(int argc, char const *argv[]) {
	
	vector<string> v = {".*..", "*.*.", "*..*", "****"};
	cout << solve(v) << endl;

	return 0;
}


