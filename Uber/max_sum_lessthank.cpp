#include<bits/stdc++.h>
using namespace std;
int main(){

	/*
	You are provided with an array containing n non-negative numbers, as well as a non-negative number sum. You must determine the number of subarrays in a whose sum is less than the sum. We can make the assumption that there is no overflow. Sample input and output for the given problem is as follows:

Input: a = [2, 5, 6]
         sum = 10
Output: 4

	*/
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int sum;
	cin>>sum;
	int answer=0;
	int right=0;
	int left=0;
	int current_sum=0;
	while(right<n){
		current_sum+=arr[right];
		while(current_sum>=sum){
			current_sum-=arr[left];
			left++;
		}
		answer+=(right-left+1);
		right++;
	}
	cout<<answer<<endl;
	return 0;
}