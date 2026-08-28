struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string word = ""; // Store full word at leaf node
};

class Solution {
public:
    vector<string> res;

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            insertWord(root, w);
        }

        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* node) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
        
        char c = board[x][y];
        if (c == '#' || !node->children[c - 'a']) return;

        node = node->children[c - 'a'];

        // Found a matching word
        if (!node->word.empty()) {
            res.push_back(node->word);
            node->word = ""; // Prevent duplicates
        }

        board[x][y] = '#'; // Mark visited

        dfs(board, x + 1, y, node);
        dfs(board, x - 1, y, node);
        dfs(board, x, y + 1, node);
        dfs(board, x, y - 1, node);

        board[x][y] = c; // Backtrack
    }
};