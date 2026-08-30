#include<bits/stdc++.h>
using namespace std;

string getEncryptedNumber(vector<int> &nums)
{
    int n = nums.size();
    for(int l=1;l<=n-2;l++)
    {
        for(int i=0;i<n-l;i++)
        {
            nums[i] = (nums[i]+nums[i+1])%10;
        }
    }
    return to_string(nums[0])+to_string(nums[1]);
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)    cin>>nums[i];

    cout<<getEncryptedNumber(nums);
    
    return 0;
}