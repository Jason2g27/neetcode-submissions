class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0){
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<vector<int>> dirs = {{-1, 0},{1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            auto [point, steps] = q.front();
            auto [row, col] = point;
            q.pop();
            for(int i = 0; i < 4; i++){
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];
                if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() 
                    || grid[r][c] != INT_MAX){
                    continue;
                }
                grid[r][c] = steps + 1;
                q.push({{r, c}, steps+1});
            }
        }
    }
};
