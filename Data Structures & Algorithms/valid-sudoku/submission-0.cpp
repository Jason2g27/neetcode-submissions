class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row;
        unordered_map<int, unordered_set<char>> col;
        unordered_map<int, unordered_set<char>> box;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char val = board[i][j];
                int boxIndex = (i/3) * 4 + j/3;
                if(val == '.'){
                    continue;
                }
                if(row[i].count(val) || col[j].count(val) || box[boxIndex].count(val)){
                    return false;
                }
                row[i].insert(val);
                col[j].insert(val);
                box[boxIndex].insert(val);
            }
        }
        return true;
    }
};
