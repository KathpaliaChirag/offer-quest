#include<bits/stdc++.h>
using namespace std;
int main(){

	/*

	Q."You have been given the string s (which consists of only uppercase English characters) and the integer k. You can replace any character in the string with another uppercase English character. This operation can be performed at most k times. After executing the preceding procedures, return the length of the longest substring containing the same letter." 

Sample input and output is shown below:

Input: s = "AABABBA", k = 1
Output: 4


	*/
	//use the concept of sliding window seeing the problem of substring
	string s;
	cin>>s;
	int n=s.length();
	int max_length=0;
	int l=0;
	int k;
	cin>>k;
	int max_freq=0;
	vector<int> freq(26,0);
	for(int r=0;r<n;r++){
			int asc=s[r]-'a';
			freq[asc]++;
			//use the max_freq to store the most frequent element
			max_freq=max(max_freq,freq[asc]);
			//here if r-l+1 gives the length of the substring and if we subtract max_freq from that then it should be less than or equal to k to satisfy
			// else shrink the window
			while(r-l+1-max_freq>k){
				freq[s[l]-'a']--;
				l++;
			}
			//store the max_length
			max_length=max(max_length,r-l+1);
	}

	cout<<max_length<<endl;
	return 0;
}