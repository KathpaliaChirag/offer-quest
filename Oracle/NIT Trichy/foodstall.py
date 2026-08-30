import requests
def getcitydata(city , price):
    
    path='https://jsonmock.hackerrank.com/api/food_outlets?city='+city+'&page=1'
    
    r=requests.get(path).json()
    print(r)
    totalpage=r['total_pages']
    perpage=r['per_page']
    
    result=[]
    for page in range(1,totalpage+1):
        path='https://jsonmock.hackerrank.com/api/food_outlets?city='+city+'&page='+str(page)
        r=requests.get(path).json()
        try:
            for record in range (0,perpage):
               if (int)(r['data'][record]['estimated_cost'])<=price:
                    result.append(r['data'][record]['name'])
        except:
             pass
        
    
    print(result)  