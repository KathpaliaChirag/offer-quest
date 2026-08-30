#include <iostream>
#include <string>
#include <vector>
using namespace std;


int rangesum(vector<int>& seg, int i, int ql, int qr, int segl, int segr) {
	//cout << "segl segr " << segl << " " << segr << endl;
	if (qr < segl || ql > segr) return 0;	
	if (segl >= ql && segr <= qr) 
		return seg[i];

	int mid = segl + (segr - segl) / 2;
	return rangesum(seg, 2*i, ql, qr, segl, mid) + rangesum(seg, 2*i + 1, ql, qr, mid+1, segr);
}


void update(vector<int>& seg, int n, int pos, int newval) {
	seg[n + pos] = newval;
    for (int p = (n + pos) / 2; p >= 1; p = p / 2) 
        seg[p] = seg[2*p] + seg[2*p + 1];
}


void solve(vector<string>& sets, vector<vector<int>>& queries) {
	int n = sets.size();
	while (__builtin_popcount(n) != 1) {
        n++;
        sets.push_back("");
    }

	// for each letter, there is a seg tree
	vector<vector<int>> seg(26, vector<int>(2*n+5, 0));
	for (char ch = 'a'; ch <= 'z'; ch++) {
		for (int i = n; i < 2*n; i++)
	        seg[ch - 'a'][i] = (find(sets[i - n].begin(), sets[i - n].end(), ch) == sets[i - n].end()) ? 0 : 1;
	    for (int i = n-1; i > 0; i--)
	        seg[ch - 'a'][i] = seg[ch - 'a'][2*i] + seg[ch - 'a'][2*i + 1];
	}


	
	for (auto& v: queries) {
		int t = v[0], a = v[1], b = v[2];
		a--; b--;
		int res = 0;
		char ch;
		switch(t) {
			case 1:
				for (ch = 'a'; ch <= 'z'; ch++) 
					res += (rangesum(seg[ch - 'a'], 1, a, b, 0, n-1) % 2);
				cout << res << '\n';
				break;

			case 2:
				update(seg[a], n, b, 0);
				break;

			case 3:
				update(seg[a], n, b, 1);
				break;

			default:
				break;
		}
	}

}



int main(int argc, char const *argv[]) {

	vector<string> sets = {"ibl", "olh", "mkd"};
	vector<vector<int>> queries = {{1, 1, 2}, {3, 1, 2}, {2, 4, 3}, {1, 1, 3}};

	solve(sets, queries);
	
	return 0;
}