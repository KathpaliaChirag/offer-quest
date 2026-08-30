import math

def solve(k,l,n):
    ans = 0
    for i in range(k,n+1):
        ans = (ans + math.comb(i-1,k-1)*math.comb(n-i,l-k)*i)%998244353
    return ans%998244353
print(solve(3,3,3))