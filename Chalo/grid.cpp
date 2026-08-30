#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {
    { 1, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 }
};

void visit(int x, int y, int N, int M, set<vector<int>> &walls, vector<vector<int>> &visited) {
    visited[x][y] = 1;
    
    for(auto dir: dirs) {
        int newX = x + dir[0];
        int newY = y + dir[1];
        
        if(newX < 1 or newX > N) continue;
        if(newY < 1 or newY > M) continue;
        if(visited[newX][newY]) continue;

        // if going to new cell crosses a wall in between, disallow it
        if(walls.count({ x, y, newX, newY }) or walls.count({ newX, newY, x, y })) continue;
        
        visit(newX, newY, N, M, walls, visited);
    }
}

int playground(int N, int M, vector<vector<int>> walls) {
    int Q = walls.size();
    
    vector<vector<int>> visited = vector<vector<int>> (N + 1, vector<int> (M + 1, 0));
    int count = 0;
    
    set<vector<int>> wallSet;
    for(auto wall: walls) {
        wallSet.insert(wall);
    }
    
    for(int row = 1; row <= N; row++) {
        for(int col = 1; col <= M; col++) {
            if(!visited[row][col]) {
                visit(row, col, N, M, wallSet, visited);
                count++;
            }
        }
    }
    
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int N,M,Q;
        cin>>N>>M>>Q;
        vector<vector<int>> walls;
        for(int i=0;i<Q;i++){
            vector<int> temp;
            for(int i=0;i<4;i++){
                int aux;
                cin>>aux;
                temp.push_back(aux);
            }
            walls.push_back(temp);

            }
            cout<<playground(N,M,walls)<<endl;
        }
    return 0;
}
