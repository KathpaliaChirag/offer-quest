import json
import requests as rq

def topArticles(limit):
    page = 0
    articles = []
    while True:
        page+=1
        url ="https://jsonmock.hackerrank.com/api/articles?page={page}"
        res= rq.get(url.format(page=page)).json()['data']
        if not res:
            break
        for atc in res:
            atc_info = dict()
            if atc['title'] is None and atc['story_title'] is None:
                continue
            elif atc['title'] is None:
                atc_info['title'] = atc['story_title']
            else:
                atc_info['title'] = atc['title']
            if atc['num_comments'] is None:
                atc_info['num_comments']=0
            else:
                atc_info['num_comments']=atc['num_comments']
            articles.append(atc_info)
    answer = sorted(articles, key= lambda x: (-x['num_comments'], x['title']))[:limit]
    return [x['title'] for x in answer]
    
print(topArticles(2))