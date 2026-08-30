#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int fLIS(vector<int>&nums){
    int n=nums.size();
    vector<int>temp;
    temp.push_back(nums[0]);
    
    for(int i=1;i<n;i++){
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
        }    
        
        else{
            int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[idx] = nums[i];
        }
    }
    return temp.size();
}


int main() {
    int n1, n2, n3;
    cin>>n1>>n2>>n3;
    vector<int>nums1(n1); 
    vector<int>nums2(n2);
    vector<int>nums3(n3);
    vector<int>nums;
    for(int i=0;i<n1;i++){
        cin>>nums1[i];
        nums.push_back(nums1[i]);
    }
    for(int i=0;i<n2;i++){
        cin>>nums2[i];
        nums.push_back(nums2[i]);
    }
    for(int i=0;i<n3;i++){
        cin>>nums3[i];
        nums.push_back(nums3[i]);
    }
    
    
    cout<<nums.size()-fLIS(nums);

    return 0;
}