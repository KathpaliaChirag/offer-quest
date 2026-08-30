def check(c1,c2):
    if c1==c2:
        return True
        
    if c1=='a' and c2=='o':
        return True
        
    if c1=='o' and c2=='a':
        return True
    
    if c1=='t' and c2=='l':
        return True
        
    if c1=='l' and c2=='t':
        return True
    
    return False
    
def recur(st,test,n,m,k,mark,deleteonce):
    if m==0:
        return True
        
    if n==0:
        return False
        
    res=False
    if check(st[n-1],test[m-1])==True:
        res=res or recur(st,test,n-1,m-1,k,True,deleteonce)
    elif k>0 and mark==True:
        res= res or recur(st,test,n-1,m,k-1,True,deleteonce)
    if deleteonce==False:
        res=res or recur(st,test,n,m-1,k,mark,True)
        
    if mark==False:
        res=res or recur(st,test,n-1,m,k,False,deleteonce)
        
    return res
    
s="aabacd"
str=["abcde","aoc","aabade"]
res=0
k=2 
for t in str:
    if recur(s,t,len(s),len(t),k,False,False):
        res+=1 
        
print(res)
        