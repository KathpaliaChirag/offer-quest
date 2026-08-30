#include <bits/stdc++.h>
using namespace std;

// recursive implementation
int GcdOfArray(vector<int>& arr, int idx)
{
	if (idx == arr.size() - 1) {
		return arr[idx];
	}
	int a = arr[idx];
	int b = GcdOfArray(arr, idx + 1);
	return __gcd(
		a, b); // __gcd(a,b) is inbuilt library function
}

int main()
{
	vector<int> arr = { 1, 2, 3 };
	cout << GcdOfArray(arr, 0) << "\n";

	arr = { 2, 4, 6, 8 };
	cout << GcdOfArray(arr, 0) << "\n";
	return 0;
}