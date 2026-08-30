import requests
import json

def getTotalGoals(team, year):
    # Write your code here
    url1="https://jsonmock.hackerrank.com/api/football_matches?year={year}&team1={team}&page={page}"
    url2="https://jsonmock.hackerrank.com/api/football_matches?year={year}&team2={team}&page={page}"
    page=1
    goals=0
    while(True):
        data1=requests.get(url1.format(year=year,team=team,page=page)).json()['data']
        data2=requests.get(url2.format(year=year,team=team,page=page)).json()['data']
        if(data1==[] and data2==[]):
            break
        for item in data1:
            goals+=int(item["team1goals"])
        for item in data2:
            goals+=int(item["team2goals"])
        page+=1
    return goals
    
team = input()
year = int(input())
result = getTotalGoals(team, year)
print(result)