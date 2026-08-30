import requests
import json

def healthCheckup(diagnosis_name, doctor_id) :
    ans,count = 0,0
    req = requests.get("https://jsonmock.hackerrank.com/api/medical_records?page=1").json()
    pages = req["total_pages"]
    for i in range(1, pages + 1) :
        req = requests.get(f"https://jsonmock.hackerrank.com/api/medical_records?page={i}").json()
        data = req['data']
        #print(data)
        for subdata in data :
            if subdata['diagnosis']['name'] == diagnosis_name and subdata['doctor']['id'] == doctor_id :
                ans+=subdata['vitals']['pulse']
                count += 1
    return (ans//count)

print(healthCheckup("Pleurisy",2))