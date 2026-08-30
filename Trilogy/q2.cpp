vector<int> solution(vector<int> balances, vector<string> requests) {
    int n = balances.size();
    using Event = tuple<long long,int,int>;
    priority_queue<Event, vector<Event>, greater<Event>> pq;
    long long lastT = 0;

    for (int i = 0; i < (int)requests.size(); ++i) {
        istringstream in(requests[i]);
        string op;
        long long t;
        int id, amt;
        in >> op >> t >> id >> amt;

        while (!pq.empty() && get<0>(pq.top()) <= t) {
            auto [ct, cid, camt] = pq.top(); pq.pop();
            balances[cid - 1] += camt;
        }
        lastT = t;

        if (id < 1 || id > n) {
            return { -(i + 1) };
        }

        if (op == "deposit") {
            balances[id - 1] += amt;
        }
        else if (op == "withdraw") {
            if (balances[id - 1] < amt) {
                return { -(i + 1) };
            }
            balances[id - 1] -= amt;
            int cb = (amt * 2) / 100;
            pq.emplace(t + 86400, id, cb);
        }
        else {
            return { -(i + 1) };
        }
    }

    while (!pq.empty() && get<0>(pq.top()) <= lastT) {
        auto [ct, cid, camt] = pq.top(); pq.pop();
        balances[cid - 1] += camt;
    }

    return balances;
} 