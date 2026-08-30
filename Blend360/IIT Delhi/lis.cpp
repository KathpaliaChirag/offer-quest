vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>lis.back()){
                lis.push_back(nums[i]);
            }
            else{
                //find the index using the binary search and place it there.
                
                int index=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                lis[index]=nums[i];
            }
        }
        return lis.size();