class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<vector<int>> dirs = {{-1, 0},{1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            auto [point, steps] = q.front();
            q.pop();
            auto [row, col] = point;
            for(auto& dir : dirs){
                int r = row + dir[0];
                int c = col + dir[1];
                if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() 
                    || grid[r][c] != INT_MAX){
                    continue;
                }
                grid[r][c] = steps+1;
                q.push({{r, c}, steps+1});
            }
        }
    }
};

