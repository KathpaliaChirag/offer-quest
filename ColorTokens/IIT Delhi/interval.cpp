#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<vector<long long>>& v) {
	sort(v.begin(), v.end(), [](vector<long long>& v1, vector<long long>& v2) {
		if (v1[1] == v2[1]) return v1[0] < v2[0];
		return v1[1] < v2[1];
	});

	int n = v.size();
	vector<long long> maxm(n);
	maxm[0] = v[0][2];

	for (int i = 0; i < n; i++) maxm[i] = max(maxm[i-1], v[i][2]);

	long long res = 0;
	for (int i = 1; i < n; i++) {
		int lo = 0, hi = i-1;
		int t = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (v[mid][1] < v[i][0]) {
				t = mid;
				lo = mid + 1;
			}
			else
				hi = mid - 1;
		} 

		//cout << "i = " << i << ", t = " << t << endl;
		if (t != -1) res = max(res, maxm[t] + v[i][2]);
	}
	return res;
}


int main(int argc, char const *argv[])
{
	vector<vector<long long>> v = {{2,3,8}, {5,6,9}, {9,11,11},{2,13,10},{2,14,13}};
	cout << solve(v) << endl;

	return 0;
}