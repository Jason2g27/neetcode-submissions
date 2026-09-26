class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int rows = grid.size(), columns = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }
        int res = 0;
        vector<vector<int>> dirs = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
        while(!q.empty()){
            auto [point, minutes] = q.front();
            auto [x, y] = point;
            q.pop();
            res = max(minutes, res);
            for(auto& dir : dirs){
                int r = x + dir[0];
                int c = y + dir[1];
                if(r < 0 || c < 0 || r >= rows || c >= columns || grid[r][c] != 1){
                    continue;
                }
                grid[r][c] = 2;
                fresh--;
                q.push({{r,c}, minutes+1});
            }
        }
        return fresh == 0 ? res : -1;
    }
};
