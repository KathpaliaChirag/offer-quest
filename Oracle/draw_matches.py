import requests
import json

def getTotalGoals(year):
    ans=0
    url="https://jsonmock.hackerrank.com/api/football_matches?year={year}&team1goals={goal1}&team2goals={goal2}"
    for goals in range(0,11):
        data1=requests.get(url.format(year=year,goal1=goals,goal2=goals)).json()['total']
        ans+=int(data1)
    return ans

year = int(input())
result = getTotalGoals(year)
print(result)