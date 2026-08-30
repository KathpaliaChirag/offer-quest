int getMinimumSwitches(vector<long long> transactions) {
    int n = transactions.size();
    long long ans = 0;
    for(int i = 0; i + 1 < n; i++){
        ans += llabs(transactions[i+1] - transactions[i]);
    }
    if(n > 0) ans += llabs(transactions[n-1]);

    return ans;
}