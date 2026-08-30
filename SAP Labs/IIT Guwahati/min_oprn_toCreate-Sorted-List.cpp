/*
Min operation to create sorted list from given list.
remove and addition of elements happen at both ends of list
ex: 
Sample input
2 3 5 10 12 4

Sample output
 10

Explanation:

Addition of 2,3,5,10,12 (added last): 5 oprn
Addition of 4
remove 2 & 3 : 2 op
insert 4: 1op
add 2 & 3: 2 op
Total 10
*/

#include<bits/stdc++.h>
using namespace std; 
int Bin(vector<int> &res ,int ele,int s,int e,int idx)
{
	
	if(s<=e)
	{
		if(s==idx)
			return s;
		int mid = s+(e-s)/2;
		if(res[mid]==ele)
			return mid;
		else if(ele<res[mid])
			return Bin(res,ele,s,mid-1,idx);
		else
			return Bin(res,ele,mid+1,e,idx);
	}
	return s;
	
}
int main()
{
	int n;
	int arr[n];
	vector<int> res;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
			
	int diff=0;
	
	for(int i=0,idx=0,pos;i<n;i++,++idx)
	{
		pos=Bin(res,arr[i],0,idx,idx);
		res.insert(res.begin()+pos,arr[i]);
		
		if(0<pos && pos<idx)
			diff +=min(pos,idx-pos)*2;		
		diff++;
		
	}
	cout<<endl<<diff<<endl;
	
	for(auto i: res)
		cout<<i<<" ";

}

