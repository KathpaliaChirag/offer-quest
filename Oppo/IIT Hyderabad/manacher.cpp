#include <iostream>
#include <string>
#include <vector>

using namespace std;

// https://cp-algorithms.com/string/manacher.html#implementation-of-manachers-algorithm
vector<int> solve(string& s2) {
	string s = "$";
	for (char ch: s2) s += string("#") + ch;
	s += "#^";

	int n = s.length();
	vector<int> p(n);
	vector<int> res(s2.length(), 1);
	int l = 0, r = 1;
	for(int i = 1; i < n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
            if (s[i + p[i] - 1] != '#') {
            	int ii = (i + p[i] - 2) / 2;
            	res[ii] = max(res[ii], p[i]);
            }
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }

    //for (int i = 0; i < n; i++)  cout << "i = " << i << ", " << p[i] << '\n';

    for (int i = 1; i < res.size(); i++)
    	res[i] = max(res[i], res[i-1]);

    return res;

}


int main(int argc, char const *argv[]) {

	//string s = "ababa"; 			// expected:1 1 3 3 5
	// string s = "aaaabcbaaaa"; 	// expected: 1 2 3 4 4 4 4 5 7 9 11
	string s = "aaabbaaa";			// expected: 1 2 3 3 3 4 6 8
	

	vector<int> res = solve(s);
	for (int x: res) cout << x << " "; cout << '\n';	

	return 0;
}
