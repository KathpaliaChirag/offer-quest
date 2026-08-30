
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int solve(vector<int>& arr,int n,int target)
	{
	int change=0;
	//iterate from backwards
	for(int i=n-1;i>0;i--){
		//here change is used to obtain the target value if arr[i]> target we need arr[i]-target value to change the arr[i] to target
		//this will enusre current_max from backwards to target 
		if(arr[i]>target){
			change+=(arr[i]-target);
		}
		else{
			change-=(target-arr[i]);
		}
	}
	//if first element + change< =target it is achieveable then.
	if(arr[0]+change<=target){
		return 1;
	}
	return 0;
}
int get_Maximum(vector<int>arr, int n ){
	int left=0;
	// here right value can be arr[n-1] because we can not change the value at the last index only decrement is allowed .
	int right=arr[n-1];
	//*max_element (first_index, last_index);
	int ans=right;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(solve(arr,n,mid)){
			ans=mid;
			right=mid-1;

		}
		else{
			left=mid+1;
		}

	}
	return ans;

	
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int res=get_Maximum(arr,n);
	cout<<res<<endl;


	return 0;
}