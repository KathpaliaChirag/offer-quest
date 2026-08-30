n=int(input())
k=int(input())
l=list(map(int,input().split()))
l.sort(reverse=True)
s=0
for i in range(k):
	s+=l[i]
print(s)	


n=int(input())
d=[]
for i in range(n):
	x=list(map(int,input().split()))
	d.append(x)
d.sort(key=lambda x:x[1])
#start=d[0][0]
#end=d[0][1]
ans=0
for i in range(n):
	if i>0 and d[i][0]>d[i-1][1]:
		ans+=(d[i][0]-d[i-1][1])
# print(ans)	




