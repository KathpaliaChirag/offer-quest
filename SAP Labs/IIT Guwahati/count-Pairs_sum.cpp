// C++ implementation of simple method to find count of pairs with given sum.
//Distinct and Duplicate pairs 
#include <bits/stdc++.h> 
using namespace std; 

// Returns number of pairs in arr[0..n-1] with sum equal to 'sum' 
int getPairsCount(int arr[], int n, int sum) 
{ 
	
	
	  //distinct pairs STARTS
	  
	  unordered_set<int> set;
        unordered_set<int> seen; 
        int count = 0;	
        for(int i=0;i<n;i++)
        {
            if(set.find(sum-arr[i])!=set.end() && seen.find(arr[i])==set.end()){
                count++;
                seen.insert(sum-arr[i]);
                seen.insert(arr[i]);
            }
            else if(seen.find(arr[i])==set.end()){
                set.insert(arr[i]);
            }

        }
        return count;      

        //distinct pairs ENDS
        
        
        
       //Duplicate pairs STARTS
       
        unordered_map<int, int> m; 
	// Store counts of all elements in map m 
	for (int i=0; i<n; i++) 
		m[arr[i]]++; 

	int twice_count = 0; 

	// iterate through each element and increment the 
	// count (Notice that every pair is counted twice) 
	for (int i=0; i<n; i++) 
	{ 
		twice_count += m[sum-arr[i]]; 
		if(m[sum-arr[i]])
		// if (arr[i], arr[i]) pair satisfies the condition, 
		// then we need to ensure that the count is 
		// decreased by one such that the (arr[i], arr[i]) 
		// pair is not considered 
		if (sum-arr[i] == arr[i]) 
			twice_count--; 
	} 

	// return the half of twice_count 
	return twice_count/2; */
	
	 //Duplicate pairs ENDS
} 

// Driver function to test the above function 
int main() 
{ 
	int arr[] = {1} ; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int sum = 2; 
	cout << "Count of pairs is "<< getPairsCount(arr, n, sum); 
	return 0; 
} 

