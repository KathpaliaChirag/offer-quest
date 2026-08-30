import requests
import json

def user_rating(city, rate):
    url="https://jsonmock.hackerrank.com/api/food_outlets?city={city}&page={page}"
    page=1
    ans=[]
    while(True):
        data1=requests.get(url.format(city=city,page=page)).json()['data']
        if(data1==[]):
            break
        for item in data1:
            if(int(item["user_rating"]["average_rating"])>=rate):
                ans.append(item["name"])
                print(item["name"],item["user_rating"]["average_rating"])
        page+=1
    return ans


def solve(city, maxcost):
    url="https://jsonmock.hackerrank.com/api/food_outlets?city={city}&page={page}"
    page=1
    ans=[]
    while(True):
        data1=requests.get(url.format(city=city,page=page)).json()['data']
        if(data1==[]):
            break
        for item in data1:
            if(int(item["estimated_cost"])<=maxcost):
                ans.append(item["name"])
        page+=1
    return ans
    
city = input()
#maxcost = int(input())
#result = solve(city, maxcost)
rate=float(input())
res2=user_rating(city,rate)
#print(result)
print(res2)