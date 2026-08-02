class Solution {
public:
    int rows, cols;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        for (int c = 0; c < cols; c++) {
            dfs(heights, 0, c, pacific);           
            dfs(heights, rows - 1, c, atlantic);   
        }

        for (int r = 0; r < rows; r++) {
            dfs(heights, r, 0, pacific);
            dfs(heights, r, cols - 1, atlantic);
        }

        vector<vector<int>> result;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& ocean){
        ocean[x][y] = true;
        for (auto& [dr, dc] : dirs) {
            int nr = x + dr;
            int nc = y + dc;

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || ocean[nr][nc]) {
                continue;
            }
            if(heights[nr][nc] >= heights[x][y]){
                dfs(heights, nr, nc, ocean);
            }
        }
    }
};
