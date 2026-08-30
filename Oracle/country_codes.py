import requests
import json

def solve(country, phone):
    
    url="https://jsonmock.hackerrank.com/api/countries?name={country}"
    ans="+"
    data1=requests.get(url.format(country=country)).json()['data']
    #print(data1)
    if(data1==[]):
        return "-1"
    l=data1[0]["callingCodes"]
    if(l==[]):
        return "-1"
    ans+=l[-1]
    ans=ans+" "+phone
    return ans

country = input()
phone=input()
result = solve(country, phone)
print(result)