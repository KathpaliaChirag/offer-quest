
from bisect import bisect_left


x = [3 ** i for i in range(1, 32)]
y = [5 ** i for i in range(1, 30)]
z = [7 ** i for i in range(1, 30)]

allitems = set()

for a in x:
	for b in y:
		if a + b < int(1e10):
			allitems.add(a + b)	

for a in x:
	for b in z:
		if a + b < int(1e10):
			allitems.add(a + b)	


for a in y:
	for b in z:
		if a + b < int(1e10):
			allitems.add(a + b)	


iteml = list(allitems)
iteml.sort()


allres = []
t = int(input())
for _ in range(t):
	x = int(input())
	deccost = int(input())
	inccost = int(input())

	indx = bisect_left(iteml, x)

	
	res = (iteml[indx] - x) * inccost
	if indx != 0:
		res = min(res, abs(iteml[indx - 1] - x) * deccost)

	allres.append(res)

print('\n'.join([str(x) for x in allres]))
