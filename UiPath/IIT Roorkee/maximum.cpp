
#include<bits/stdc++.h>
using namespace std;
#define ll longlong
int solve(vector<int>& arr,int n,int target){
	int change=0;
	for(int i=n-1;i>0;i--){
		if(arr[i]>target){
			change+=(arr[i]-target);
		}
		else{
			change-=(target-arr[i]);
		}
	}
	if(arr[0]+change<=target){
		return 1;
	}
	return 0;
}
int get_Maximum(vector<int>arr, int n ){
	int left=0;
	int right=arr[n-1];
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