#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// resprime is the result (max dist node) from the parent of v which isn't present in the subtree rooted at v
void dfs(int v, string& s, int resprime, vector<int>& res, vector<int>& height) {
	if (v >= s.length() || s[v] == '0') return;
	//cout << "for v, resprime " << v << " " << resprime << endl;

	res[v] = max(height[v], resprime + 1);
	
	int resprimecopy = resprime;
	int lh = (2*v + 1 < res.size()) ? height[2*v + 1] : -1;
	int rh = (2*v + 2 < res.size()) ? height[2*v + 2] : -1;

	resprime = max(resprimecopy, rh) + 1;
	dfs(2*v + 1, s, resprime, res, height);
	resprime = max(resprimecopy, lh) + 1;
	dfs(2*v + 2, s, resprime, res, height);
}


vector<int> solve(string& s) {
	int n = s.length();
	vector<int> height(n, -1);
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '0') continue;
		int h1 = 2*i + 1 < n ? height[2*i + 1] : -1;
		int h2 = 2*i + 2 < n ? height[2*i + 2] : -1;
		height[i] = max(h1, h2) + 1;
	}

	vector<int> res(n, -1);
	res[0] = height[0];
	dfs(0, s, -1, res, height);

	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') v.push_back(res[i]);
	}

	return v;
}

int main() {
	string s = "111110000010000,";
	vector<int> v = solve(s);
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' '; cout << '\n';
}
