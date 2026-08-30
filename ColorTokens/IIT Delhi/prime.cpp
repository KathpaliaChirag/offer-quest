#include "bits/stdc++.h"
using namespace std;

#define int long long

signed main() {
  int tt = 1;
  vector<int> v3, v5, v7;
    int prv = 1;
    for(int i = 1; i <= 20 and prv * 3 <= INT_MAX; i++) {
      prv *= 3;
      v3.push_back(prv);
    }
    prv = 1;
    for(int i = 1; i <= 20 and prv * 5 <= INT_MAX; i++) {
      prv *= 5;
      v5.push_back(prv);
    }
    prv = 1;
    for(int i = 1; i <= 20 and prv * 7 <= INT_MAX; i++) {
      prv *= 7;
      v7.push_back(prv);
    }
    vector<int> fin;
    for(int i = 0; i < v3.size(); i++) {
      for(int j = 0; j < v5.size(); j++) {
        fin.push_back(v3[i] + v5[j]);
      }
    }
    for(int i = 0; i < v3.size(); i++) {
      for(int j = 0; j < v7.size(); j++) {
        fin.push_back(v3[i] + v7[j]);
      }
    }
    for(int i = 0; i < v5.size(); i++) {
      for(int j = 0; j < v7.size(); j++) {
        fin.push_back(v5[i] + v7[j]);
      }
    }
    sort(fin.begin(), fin.end());
  cin >> tt;
  while(tt--) {
  	int n, inc, dec;
  	cin >> n >> dec >> inc;
  	int bada = lower_bound(fin.begin(), fin.end(), n) - fin.begin();
  	int chota = bada - 1;
  	int ans = 1e18;
  	ans = min(ans, (fin[bada] - n) * inc);
  	if(chota >= 0)
	  	ans = min(ans, (n - fin[chota]) * dec);
  	cout << ans << endl;
  }
  return 0;
}