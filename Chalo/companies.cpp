#include<bits/stdc++.h>
using namespace std;
vector<int> customerService(vector<vector<int>> &orders, int k, int w) {
    int n = orders.size();
    // min heap
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> placedOrders; // order_duration, order_time, order_index
    int currentTime = 0;
    int nextOrderIndex = 0;
    
    vector<int> orderCost(n);
    
    while(nextOrderIndex < n or !placedOrders.empty()) {
        
        // push the orders available at currentTime to the heap
        while(nextOrderIndex < n and currentTime >= orders[nextOrderIndex][0]) {
            int orderDuration = orders[nextOrderIndex][1];
            int orderTime = orders[nextOrderIndex][0];
            int orderIndex = nextOrderIndex;
            placedOrders.push({ orderDuration, orderTime, orderIndex });
            nextOrderIndex++;
        }
        
        // if nothing available at current time
        if(placedOrders.empty()) {
            currentTime = orders[nextOrderIndex][0];
            continue;
        }
        
        // handle next order
        auto nextOrder = placedOrders.top();
        placedOrders.pop();
        
        int waitTime = currentTime - get<1>(nextOrder);
        int prepTime = get<0>(nextOrder);
        int orderIndex = get<2>(nextOrder);
        
        orderCost[orderIndex] = max(k * prepTime - w * waitTime, 0);
        currentTime += prepTime;
    }
    
    return orderCost;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k, w;
        cin >> n >> k >> w;
        vector<vector<int>> orders = vector<vector<int>>(n, vector<int> (2));
        for(int i = 0; i < n; i++)
            cin >> orders[i][0] >> orders[i][1];
        
        vector<int> costs = customerService(orders, k, w);
        for(int cost: costs)
            cout << cost << " ";
        cout << "\n";
    }
    
    return 0;
}