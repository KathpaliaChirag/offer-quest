int answer(vector<int> arr) {
        priority_queue<int> pq;
        for(auto p:arr) pq.push(p);
        int cnt=0;
        while(pq.size()>1)
        {
            auto c1=pq.top();
            pq.pop();
            auto c2=pq.top();
            pq.pop();
            cnt++;
            c1--;
            cnt++;
            c2--;
            if(c1) pq.push(c1);
            if(c2) pq.push(c2);
        }
        if(!pq.empty()) cnt++;
        return cnt;        
    }
