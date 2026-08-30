#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long modPower(long long a, long long b){
    long long ans = 1;
    a = a % mod;
    while(b){
        if(b%2 == 1){
            ans = ans * a % mod;
        }
        a = a*a %mod;
        b = b>>1;
    }
    return ans;
}
int find(int n, int r){
    if(r ==0 || r == n) return 1;
    if(r > n-r) r = n-r;
    int ans = 1;
    for(int i = 0 ; i < r; i++){
        ans = ans * (n - i) % mod;
        ans  = (ans * modPower(i+ 1,mod - 2)) % mod;
    }
    return ans;
}
long long nCr(int n, int r){
    if(r == 0 || r == n) return 1;

    if(r > n -r){
        r = n-r;
    }
    long long ans = 1;
    for(int i = 0 ; i < r; i++){
        ans  = ans * (n-i) % mod;
        ans = ans * modPower(i+1,mod-2) % mod;
    }
    return ans;

}
// long long modPower(int a, int b){
//     int ans = 1;
//     a = a % mod;
//     while(b){
//         if(b%2 == 1){
//             ans = ans * a % mod;
//         }
//         a = a*a %mod;
//         b = b>>1;
//     }
//     return ans;
// }

int main(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    int num;
    vector<int> arr;
    while(ss >> num)    arr.push_back(num);
    int sum;
    cin>>sum;
    sort(arr.begin(),arr.end());
    unordered_map<int,int> freq;
    for(auto v : arr) 
        {freq[v]++;}
    // vector<pair<int,int>> ans;
    // cout<<find(4,2)<<" ";
    int cnt = 0;
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue; 
        int val1 = arr[i];
        int low = i+1, high = n-1;
        // pair<int,int> a;
        
        while(low < high){
            int mid = (low + high) / 2;
            int val = (abs(val1 + arr[mid]) + abs(val1 - arr[mid]));
            // cout<< val << " "; 
            if(val == sum){
                if(val1 != arr[mid]){
                    cnt+= (freq[arr[mid]] * freq[val1]);
                
                }
                else{
                    cout<<freq[arr[mid]]<<" ";
                    cout<<find(freq[arr[mid]],2)<<" ";
                    // cnt+= 
                }
                // ans.push_back({val1,arr[mid]});
                break;
            } 
            if(val > sum){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
    }
    // for(auto p : ans) cout<<p.first << " " <<p.second;
    cout<<cnt;

}