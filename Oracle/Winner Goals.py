import requests
def getWinnerTotalGoals(competition, year):
    # Write your code here
    path="https://jsonmock.hackerrank.com/api/football_competitions?name="+competition+"&year="+str(year)
    r=requests.get(path).json()
    winner=r['data'][0]['winner']
    
    path="https://jsonmock.hackerrank.com/api/football_matches?competition="+competition+"&year="+str(year)+"&team1="+winner+"&page=1"
    r=requests.get(path).json()
    totalpage=r['total_pages']
    perpage=r['per_page']
    score=0
   
    for page in range(1,totalpage+1):
        path="https://jsonmock.hackerrank.com/api/football_matches?competition="+competition+"&year="+str(year)+"&team1="+winner+"&page="+str(page)
        r=requests.get(path).json()
        try:
            for record in range(0,perpage):
                score=score+(int)(r['data'][record]['team1goals'])
        except:
           pass
             
    path="https://jsonmock.hackerrank.com/api/football_matches?competition="+competition+"&year="+str(year)+"&team2="+winner+"&page=1"
    r=requests.get(path).json()
    totalpage=r['total_pages']
    perpage=r['per_page']
    
    for page in range(1,totalpage+1):
        path="https://jsonmock.hackerrank.com/api/football_matches?competition="+competition+"&year="+str(year)+"&team2="+winner+"&page="+str(page)
        r=requests.get(path).json()
        try:
            for record in range(0,perpage):
                score=score+(int)(r['data'][record]['team2goals'])
        except:
           pass
        
    return score
if __name__ == '__main__':