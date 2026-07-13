class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0] && traverse(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false; // Fix #4: Must return false if loops finish without success
    }

    bool traverse(vector<vector<char>>& board, string& word, int i, int j, int cur){
        // Fix #2: If we matched the entire word, we are done!
        if(word.size() == cur){
            return true;
        }

        // Fix #1: Corrected off-by-one bounds checks (>= instead of >)
        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0){
            return false;
        }

        if(word[cur] != board[i][j] || board[i][j] == '#'){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        // Fix #3: Corrected all parameter arguments and passed cur + 1
        bool found = traverse(board, word, i, j+1, cur+1) || 
                     traverse(board, word, i, j-1, cur+1) ||
                     traverse(board, word, i+1, j, cur+1) || 
                     traverse(board, word, i-1, j, cur+1);

        // Fix #4: Restore the cell so other paths can use it
        board[i][j] = temp; 

        return found;
    }
};