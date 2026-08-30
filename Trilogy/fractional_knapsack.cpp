#include<bits/stdc++.h>
using namespace std;
int main(){

	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int B;
	cin>>B;
	sort(arr.begin(),arr.end(),greater<int>());
	vector<int> suffix(n+1,0);
	int count=0;
	for(int i=n-1;i>=0;i--){
		suffix[i]=suffix[i+1]+arr[i];
	}
	//sum can't be achieved
	if(suffix[0]<B){
		cout<<-1<<endl;
	}
	
	else{
	
	
	
	for(int i=0;i<n && B>0;){
		//if possible to this greedily
		if(B>=arr[i]){
			B-=arr[i];
			i++;
		}
		else{
			//if it can be achieved through remaining numbers skip this index and move forward and we can obtain the B.
			if(suffix[i+1]>=B){
				i++;
			}
			else{
				////divide the number till arr[i]> B and increment the count
				while(arr[i]>B){
					arr[i]/=2;
					count++;
					//cout<<count<<endl;
				}
				B-=arr[i];

			}
		}
	}
	cout<<count<<endl;
	}



	return 0;
}
/*
test case 1

3 
1 1 32
10
output=2

6
1 1 1 2 2 512
128
output=5

4 
1 1 4 16
23
output -1

*/