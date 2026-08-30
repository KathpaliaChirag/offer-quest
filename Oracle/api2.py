import requests
import json
def getRelevant(city,maxCost):
	url="https://jsonmock.hackerrank.com/api/food_outlets?city="+city
	req=requests.get(url).json()
	#results=json.loads(response.content);
	pages=req['total_pages']
	res=[]
	tot=0
	for i in range(1,pages+1):
		urli=f"https://jsonmock.hackerrank.com/api/food_outlets?city="+city+"&page="+str(i)
		req1=requests.get(urli).json()
		#res1=json.loads(response1.content);
		for subdata in req1['data']:
			if(subdata['estimated_cost']<=maxCost):
				res.append(subdata['name'])
	return res
print(getRelevant("Houston",200))				