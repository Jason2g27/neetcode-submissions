class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int cur = dfs(grid, i, j);
                    res = res > cur ? res : cur;
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, int x, int y){
        if(x >= grid.size() || x < 0 || y < 0 || y >= grid[0].size() || grid[x][y] == 0){
            return 0;
        }
        grid[x][y] = 0;
        return 1 + dfs(grid, x + 1, y) + dfs(grid, x - 1, y) + dfs(grid, x, y + 1) + dfs(grid, x, y - 1);
    }
};
