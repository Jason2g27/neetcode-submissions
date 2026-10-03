class Solution {
public:
    vector<vector<int>> paths;
    int uniquePaths(int m, int n) {
        paths.assign(m, vector<int>(n, -1));
        return traverse(m, n, 0, 0);
    }

    int traverse(int m, int n, int x, int y){
        if(x == m-1 && y == n-1){
            return 1;
        }
        if(x >= m || y >= n){
            return 0;
        }
        if(paths[x][y] != -1){
            return paths[x][y];
        }
        return paths[x][y] = traverse(m, n, x+1, y) + traverse(m, n, x, y+1);
    }
};
