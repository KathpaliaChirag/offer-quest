n=int(input())
d=[]

start = None
end = None
for i in range(n):
	x=list(map(int,input().split()))
	d.append(x)
	if start is None or x[0] < start:
		start = x[0]
	if end is None or x[1] > end:
		end = x[1]
#d = [[2,3],[4,5],[6,7],[8,9],[1,10],[11,12]]
# sort by start time
d.sort(key=lambda x:x[0])


merged = []
merged.append(d[0])
for i in range(1, n):
	if merged[-1][1] < d[i][0]:
		merged.append(d[i])
	else:
		merged[-1][1] = max(merged[-1][1], d[i][1])

ans = end - start
for item in merged:
	ans -= item[1] - item[0]
print(ans)